#include "../includes/Commands.hpp"
#include "../includes/Server.hpp"
#include "../includes/Client.hpp"
#include "../includes/Channel.hpp"
#include "../includes/Reply.hpp"
#include "../includes/Bot.hpp"
#include "../includes/File.hpp"
#include <fstream>
#include <algorithm>
#include <cctype>

// general prototype
const std::string Commands::_commandsTab[Commands::_numCommands] = {
	"PART",
	"NICK",
	"USER",
	"PASS",
	"PING",
	"JOIN",
	"PRIVMSG",
	"NOTICE",
	"USERHOST",
	"QUIT",
	"TOPIC",
	"INVITE",
	"KICK",
	"MODE",
	"SEND",
	"ACCEPT"
};

const Commands::CommandFunction Commands::_commandsFunctions[Commands::_numCommands] = {
	&Commands::part,
	&Commands::nick,
	&Commands::user,
	&Commands::pass,
	&Commands::ping,
	&Commands::join,
	&Commands::privmsg,
	&Commands::notice,
	&Commands::userhost,
	&Commands::quit,
	&Commands::topic,
	&Commands::invite,
	&Commands::kick,
	&Commands::mode,
	&Commands::sendFile,
	&Commands::acceptFile
};

Commands::Commands(Server *server) : _server(server) {}

Commands::~Commands() {}


// helper func for case insensitive comparison
static bool strcasecmp_irc(const std::string &a, const std::string &b)
{
	if (a.length() != b.length())
		return false;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (std::tolower(static_cast<unsigned char>(a[i])) != std::tolower(static_cast<unsigned char>(b[i])))
			return false;
	}
	return true;
}

// helper func to convert string to lowercase
static std::string toLower_irc(const std::string &str)
{
	std::string result = str;
	for (size_t i = 0; i < result.length(); i++)
	{
		result[i] = std::tolower(static_cast<unsigned char>(result[i]));
	}
	return result;
}

std::string	Commands::getAnswer(Client &client, Message &msg)
{
	// loop in the functions to match, if not find return unknown cmd
	for (int i = 0; i < _numCommands; i++) {
		if (msg.command == _commandsTab[i]) {
			return (this->*_commandsFunctions[i])(client, msg);
		}
	}
	return ERR_UNKNOWNCOMMAND(_server->getServerName(), client.getNick(), msg.command);
}

std::string	Commands::ping(Client &client, Message &msg)
{
	std::string token = msg.params.empty() ? _server->getServerName() : msg.params[0];
	return PONG(client_id(client.getNick(), client.getUser(), client.getHost()), token);
}

std::string Commands::userhost(Client&, Message&) {
	return "";  // on ignore
}

std::string Commands::privmsg(Client &client, Message &msg)
{
	if (msg.params.empty())
		return ERR_NEEDMOREPARAMS(_server->getServerName(), client.getNick(), "PRIVMSG");

	if (msg.remaining.empty())
		return ERR_NOTEXTTOSEND(_server->getServerName(), client.getNick());

	std::string target = msg.params[0];
	std::string message = msg.remaining;

	if (!target.empty() && (target[0] == '#' || target[0] == '&')) {
		Channel *channel = _server->findOrCreateChannel(target);

		// Check if sender is in the channel
		if (!channel->isMember(client.getFd()))
			return ERR_NOTONCHANNEL(_server->getServerName(), client.getNick(), target);

		std::string privmsgStr = PRIVMSG(client.getNick(), client.getUser(), client.getHost(), target, message);

		// Send to all members except the sender
		std::vector<Client*> members = channel->getMembers();
		for (size_t i = 0; i < members.size(); i++) {
			if (members[i]->getFd() != client.getFd()) {
				_server->answerClient(members[i]->getFd(), privmsgStr);
			}
		}

		// bot answers to any message with !
		if (!message.empty() && message[0] == '!') {
			Message botMsg = msg;
			botMsg.command = message;
			_server->getBot().onChannelMessage(*_server, client, target, botMsg);
		}
		
		return "";
	} else {
		if (strcasecmp_irc(target, _server->getBot().getNick())) {
			_server->getBot().onMessage(*_server, client, msg);
			return "";
		}
		Client *targetClient = _server->findClientByNick(target);
		if (targetClient == NULL)
			return ERR_NOSUCHNICK(_server->getServerName(), client.getNick(), target);

		std::string privmsgStr = PRIVMSG(client.getNick(), client.getUser(), client.getHost(), target, message);
		_server->answerClient(targetClient->getFd(), privmsgStr);
		return "";
	}
}

std::string	Commands::notice(Client &client, Message &msg)
{
	if (msg.params.empty())
		return "";

	if (msg.remaining.empty())
		return "";

	std::string target = msg.params[0];
	std::string message = msg.remaining;

	if (!target.empty() && (target[0] == '#' || target[0] == '&')) {
		Channel *channel = _server->findOrCreateChannel(target);

		// Check if sender is in the channel
		if (!channel->isMember(client.getFd()))
			return "";

		std::string noticeStr = NOTICE(client.getNick(), client.getUser(), client.getHost(), target, message);

		// Send to all members except the sender
		std::vector<Client*> members = channel->getMembers();
		for (size_t i = 0; i < members.size(); i++) {
			if (members[i]->getFd() != client.getFd()) {
				_server->answerClient(members[i]->getFd(), noticeStr);
			}
		}

		if (_server->getBot().isInChannel(target) && !message.empty() && message[0] == '!') {
			Message botMsg = msg;
			botMsg.command = message;
			_server->getBot().onChannelMessage(*_server, client, target, botMsg);
		}
		
		return "";
	} else {
		if (strcasecmp_irc(target, _server->getBot().getNick())) {
			_server->getBot().onMessage(*_server, client, msg);
			return "";
		}
		Client *targetClient = _server->findClientByNick(target);
		if (targetClient == NULL)
			return "";

		std::string noticeStr = NOTICE(client.getNick(), client.getUser(), client.getHost(), target, message);
		_server->answerClient(targetClient->getFd(), noticeStr);
		return "";
	}
}

// std::string Commands::user(Client &client, Message &msg)
// {
// 	if (!msg.params[0].empty())
// 		Client	client = getClientByNick(nickname)
// 		client.setNickname(msg.params[0])
// 	return (...)
// }

std::string	Commands::join(Client &client, Message &msg)
{
	// Vérifie qu'il y a au moins un paramètre (le nom du channel)
	if (msg.params.empty())
		return ERR_NEEDMOREPARAMS(_server->getServerName(), client.getNick(), "JOIN");

	std::string channelName = msg.params[0];

	// Vérifie que le nom commence par # ou &
	if (channelName.empty() || (channelName[0] != '#' && channelName[0] != '&'))
		return ERR_NOSUCHCHANNEL(_server->getServerName(), client.getNick(), channelName);

	// Trouve ou crée le channel
	Channel *channel = _server->findOrCreateChannel(channelName);

	// Vérifie si le client est déjà dans le channel
	if (channel->isMember(client.getFd()))
		return "";  // Déjà dans le channel, ne rien faire

	if (channel->isInviteOnly() && !channel->isInvited(client.getFd()))
		return ERR_INVITEONLYCHAN(_server->getServerName(), client.getNick(), channelName);

	// check channel password
	if (channel->hasKey())
		if (msg.params.size() < 2 || msg.params[1] != channel->getKey())
			return ERR_BADCHANNELKEY(_server->getServerName(), client.getNick(), channelName);

	// check userlimit
	if (channel->isUserLimited())
	{
		size_t currentCount = channel->getMembers().size();
		if (currentCount >= channel->getUserLimit())
			return ERR_CHANNELISFULL(_server->getServerName(), client.getNick(), channelName);
	}

	// Remove from invite list after joining
	channel->removeInvited(client.getFd());

	// Message JOIN à broadcaster à tous les membres du channel
	std::string joinMsg = JOIN(client.getNick(), client.getUser(), client.getHost(), channelName);

	// Broadcaster le JOIN à tous les membres actuels du channel
	std::vector<Client*> members = channel->getMembers();
	for (size_t i = 0; i < members.size(); i++) {
		_server->answerClient(members[i]->getFd(), joinMsg);
	}

	// Ajoute le client au channel
	channel->addMember(client);

	// Si c'est le premier membre, il devient opérateur
	if (members.empty()) {
		channel->addOperator(client);
	}

	_server->answerClient(client.getFd(), joinMsg);

	// Envoie pas de topic (le message fonctionne mais irssi le bloque idk why, surement pollution visuelle)
	_server->answerClient(client.getFd(), RPL_NOTOPIC(_server->getServerName(), client.getNick(), channelName));

	// Envoie la liste des membres (recharger pour inclure le nouveau membre)
	members = channel->getMembers();
	std::string namesList = "";
	for (size_t i = 0; i < members.size(); i++) {
		if (i > 0)
			namesList += " ";

		if (channel->isOperator(members[i]->getFd()))
			namesList += "@";
		namesList += members[i]->getNick();
	}
	_server->answerClient(client.getFd(), RPL_NAMREPLY(_server->getServerName(), client.getNick(), channelName, namesList));

	// Envoie la fin de la liste
	_server->answerClient(client.getFd(), RPL_ENDOFNAMES(_server->getServerName(), client.getNick(), channelName));

	return "";
}

std::string	Commands::part(Client &client, Message &msg)
{
	// Vérifie qu'il y a au moins un paramètre (le nom du channel)
	if (msg.params.empty())
		return ERR_NEEDMOREPARAMS(_server->getServerName(), client.getNick(), "PART");

	std::string channelList = msg.params[0];
	std::string reason = "";

	// Récupère la raison si elle existe
	if (msg.params.size() > 1) {
		reason = msg.params[1];
	}

	// Parse la liste des channels (séparés par des virgules)
	std::vector<std::string> channels;
	std::string currentChannel = "";
	for (size_t i = 0; i < channelList.size(); i++) {
		if (channelList[i] == ',') {
			if (!currentChannel.empty()) {
				channels.push_back(currentChannel);
				currentChannel = "";
			}
		} else if (channelList[i] != ' ' && channelList[i] != '\t') {
			// Ignore les espaces et tabulations
			currentChannel += channelList[i];
		}
	}
	if (!currentChannel.empty()) {
		channels.push_back(currentChannel);
	}

	// Traite chaque channel
	for (size_t i = 0; i < channels.size(); i++) {
		std::string channelName = channels[i];

		// Trouve le channel
		Channel *channel = _server->findOrCreateChannel(channelName);

		// Vérifie si le client est dans le channel
		if (!channel->isMember(client.getFd()))
		{
			// Can't return here because we're in a loop, need to send directly
			_server->answerClient(client.getFd(), ERR_NOTONCHANNEL(_server->getServerName(), client.getNick(), channelName));
			continue; // Passe au channel suivant
		}

		// Récupère la liste des membres avant de retirer le client
		std::vector<Client*> members = channel->getMembers();

		// Construit le message PART à envoyer à tous les membres
		std::string partMsg = PART(client.getNick(), client.getUser(), client.getHost(), channelName, reason);

		// Envoie le message PART à tous les membres du channel (y compris celui qui part)
		for (size_t j = 0; j < members.size(); j++) {
			_server->answerClient(members[j]->getFd(), partMsg);
		}

		// Retire le client du channel
		channel->removeMember(client.getFd());
		channel->removeOperator(client.getFd());

		// Si le channel est vide, le supprimer
		if (channel->isEmpty()) {
			_server->removeChannel(channelName);
		}
	}

	return "";
}

std::string Commands::quit(Client &client, Message &msg)
{
	std::string reason;
	if (msg.params.empty() || msg.params[0].empty())
		reason = "Client Quit";
	else
		reason = msg.remaining;
	std::string quitMsg =
		":" + _server->getClientPrefix(client) + " QUIT :" + reason + "\r\n";
	std::map<int, Client> &clients = _server->getClients();
	for (std::map<int, Client>::iterator it = clients.begin();
		 it != clients.end(); ++it)
	{
		if (it->first != client.getFd())
			_server->answerClient(it->first, quitMsg);
	}
	_server->answerClient(client.getFd(), quitMsg);
	close(client.getFd());
	return "";
}

bool	Commands::nicknameExists(const std::string &nickname)
{
	Client	*client = _server->findClientByNick(nickname);
	if (client == NULL)
		return (false);
	return (true);
}

bool	Commands::isvalideNickname(const std::string &nickname)
{
	if (nickname.length() > 9)
			return (false);
	if (strcasecmp_irc(nickname, "bot"))
		return (false);
	for (int i = 0; i < static_cast<int>(nickname.length()); i++)
	{
		if(!std::isalpha(nickname[i]) && i == 0)
			return(false);
		char c = nickname[i];
		bool isLetter = std::isalpha(c);
		bool isDigit = std::isdigit(c);
		bool isSpecial = (c == '[' || c == ']' || c == '\\' ||
				c == '`' || c == '^' || c == '{' || c == '}');
		if (!isLetter && !isDigit && !isSpecial)
			return false;
	}
	return(true);
}

std::string Commands::nick(Client &client, Message &msg)
{
	if (msg.params.empty() || msg.params[0].empty())
	{
		std::string currentNick = client.getNick().empty() ? "*" : client.getNick();
		return ERR_NONICKNAMEGIVEN(_server->getServerName(), currentNick);
	}

	if (!client.hasPass())
	{
		std::string currentNick = client.getNick().empty() ? "*" : client.getNick();
		return ERR_PASSWDMISMATCH(_server->getServerName(), currentNick);
	}

	const std::string &newNick = msg.params[0];
	if (!isvalideNickname(newNick))
	{
		std::string currentNick = client.getNick().empty() ? "*" : client.getNick();
		return ERR_ERRONEUSNICKNAME(_server->getServerName(), currentNick, newNick);
	}
	std::string oldNick = client.getNick();
	Client *existingClient = _server->findClientByNick(newNick);
	if (existingClient != NULL && existingClient->getFd() != client.getFd())
	{
		std::string currentNick = oldNick.empty() ? "*" : oldNick;
		return ERR_NICKNAMEINUSE(_server->getServerName(), currentNick, newNick);
	}
	// store nick in lowercase
	std::string lowerNick = toLower_irc(newNick);
	client.setNick(lowerNick);
	client.setHasNick(true);

	if (oldNick.empty())
	{
		// first registration
		if (client.hasUser())
		{
			client.setIsRegistered(true);
			return RPL_WELCOME(_server->getServerName(), lowerNick, client.getUser(), client.getHost());
		}
		return "";
	}
	else
	{
		std::string nickMsg = NICK(oldNick, client.getUser(), client.getHost(), lowerNick);
		
		_server->answerClient(client.getFd(), nickMsg);

		std::map<std::string, Channel> &channels = _server->getChannels();
		for (std::map<std::string, Channel>::iterator it = channels.begin(); 
			 it != channels.end(); ++it)
		{
			Channel &channel = it->second;
			if (channel.isMember(client.getFd()))
			{
				std::vector<Client*> members = channel.getMembers();
				for (size_t i = 0; i < members.size(); i++)
				{
					if (members[i]->getFd() != client.getFd())
						_server->answerClient(members[i]->getFd(), nickMsg);
				}
			}
		}
		
		return "";
	}
}

std::string Commands::pass(Client &client, Message &msg)
{
	if (msg.params.empty())
	{
		std::string currentNick = client.getNick().empty() ? "*" : client.getNick();
		return ERR_NEEDMOREPARAMS(_server->getServerName(), currentNick, "PASS");
	}

	if (client.isRegistered())
		return ERR_ALREADYREGISTERED(_server->getServerName(), client.getNick());

	std::string providedPass = msg.params[0];
	if (providedPass == _server->getPassword())
		client.setHasPass(true);
	else
	{
		std::string currentNick = client.getNick().empty() ? "*" : client.getNick();
		return ERR_PASSWDMISMATCH(_server->getServerName(), currentNick);
	}
	return "";
}

std::string Commands::user(Client &client, Message &msg)
{
	if (msg.params.size() < 3 || msg.remaining.empty())
	{
		std::string currentNick = client.getNick().empty() ? "*" : client.getNick();
		return ERR_NEEDMOREPARAMS(_server->getServerName(), currentNick, "USER");
	}

	if (!client.hasPass())
	{
		std::string currentNick = client.getNick().empty() ? "*" : client.getNick();
		return ERR_PASSWDMISMATCH(_server->getServerName(), currentNick);
	}

	if (client.isRegistered())
		return ERR_ALREADYREGISTERED(_server->getServerName(), client.getNick());

	client.setUser(msg.params[0]);
	client.setHost(msg.params[1]);
	client.setReal(msg.remaining);
	client.setHasUser(true);
	if (client.hasNick())
	{
		client.setIsRegistered(true);
		return RPL_WELCOME(_server->getServerName(), client.getNick(), client.getUser(), client.getHost());
	}
	return ""; // Waiting for NICK command
}

std::string	Commands::topic(Client &client, Message &msg)
{
	//check si 0 param -> erreur (a voir sil faut un nb de param max)
	if (msg.params.empty())
		return ERR_NEEDMOREPARAMS(_server->getServerName(), client.getNick(), "TOPIC");

	//check si le channel existe et si l'user est dans le channel
	std::string channelName = msg.params[0];
	Channel *channel = _server->findChannel(channelName);
	
	// If channel doesn't exist OR user is not in it, return ERR_NOTONCHANNEL
	if (!channel || !channel->isMember(client.getFd()))
		return ERR_NOTONCHANNEL(_server->getServerName(), client.getNick(), channelName);

	//si pas de topic dans la commande -> afficher topic actuel (reply norme rfc)
	if (msg.remaining.empty())
	{
		std::string currentTopic = channel->getTopic();
		if (currentTopic.empty())
			return RPL_NOTOPIC(_server->getServerName(), client.getNick(), channelName);
		else
			return RPL_TOPIC(_server->getServerName(), client.getNick(), channelName, currentTopic);
	}
	if (channel->isTopicOp() && !channel->isOperator(client.getFd()))
		return ERR_CHANOPRIVSNEEDED(_server->getServerName(), client.getNick(), channelName);

	//modifier le topic
	std::string newTopic = msg.remaining;
	channel->setTopic(newTopic);

	// Broadcast le changement dans le chan
	std::string topicMsg = TOPIC(client.getNick(), client.getUser(), client.getHost(), channelName, newTopic);
	_server->sendToChannel(channelName, topicMsg, -1);
	
	return "";
}

std::string	Commands::invite(Client &client, Message &msg)
{
	//INVITE <nickname> <channel> check au moins 2 arg car tout ce qui est apres channel est ignore
	if (msg.params.size() < 2)
		return ERR_NEEDMOREPARAMS(_server->getServerName(), client.getNick(), "INVITE");
	//verif chan existe + user qui inv + cible qui existe + si cible deja sur channel
	std::string targetNick = msg.params[0];
	std::string channelName = msg.params[1];

	Channel *channel = _server->findChannel(channelName);
	Client *target = _server->findClientByNick(targetNick);

	// If channel doesn't exist OR user is not in it, return ERR_NOTONCHANNEL
	if (!channel || !channel->isMember(client.getFd()))
		return ERR_NOTONCHANNEL(_server->getServerName(), client.getNick(), channelName);
	if (!target)
		return ERR_NOSUCHNICK(_server->getServerName(), client.getNick(), targetNick);
	// RFC 2812: Cannot invite yourself
	if (target->getFd() == client.getFd())
		return ERR_USERONCHANNEL(_server->getServerName(), client.getNick(), targetNick, channelName);
	if (channel->isMember(target->getFd()))
		return ERR_USERONCHANNEL(_server->getServerName(), client.getNick(), targetNick, channelName);
	//si channel a mode +i et que l'inv est operator ajouter la cible a une liste d'inv sinon error
	if (channel->isInviteOnly() && !channel->isOperator(client.getFd()))
		return ERR_CHANOPRIVSNEEDED(_server->getServerName(), client.getNick(), channelName);

	//Envoyer msg a celui qui inv (norme rfc2812)
	_server->answerClient(client.getFd(), 
		RPL_INVITING(_server->getServerName(), client.getNick(), targetNick, channelName));

	//envoi msg d'inv a la cible (norme rfc2812)
	std::string inviteMsg = INVITE(client.getNick(), client.getUser(), client.getHost(), 
									targetNick, channelName);
	_server->answerClient(target->getFd(), inviteMsg);

	channel->addInvited(*target);
	return "";
}

std::string	Commands::kick(Client &client, Message &msg)
{
	if (msg.params.size() < 2)
		return ERR_NEEDMOREPARAMS(_server->getServerName(), client.getNick(), "KICK");
	std::string targetNick = msg.params[1];
	std::string channelName = msg.params[0];
	Channel *channel = _server->findChannel(channelName);
	
	if (!channel)
		return ERR_NOSUCHCHANNEL(_server->getServerName(), client.getNick(), channelName);
	if (!channel->isMember(client.getFd()))
		return ERR_NOTONCHANNEL(_server->getServerName(), client.getNick(), channelName);
	
	// Check if user is operator BEFORE checking if target exists
	if (!channel->isOperator(client.getFd()))
		return ERR_CHANOPRIVSNEEDED(_server->getServerName(), client.getNick(), channelName);
	
	// Now check if target exists and is in channel
	Client *target = _server->findClientByNick(targetNick);
	if (!target)
		return ERR_NOSUCHNICK(_server->getServerName(), client.getNick(), targetNick);
	if (!channel->isMember(target->getFd()))
		return ERR_USERNOTINCHANNEL(_server->getServerName(), client.getNick(), targetNick, channelName);

	if (target->getFd() == client.getFd())
		return ERR_CHANOPRIVSNEEDED(_server->getServerName(), client.getNick(), channelName);
	
	std::string reason = msg.remaining.empty() ? client.getNick() : msg.remaining;
	std::string kickMsg = KICK(client.getNick(), client.getUser(), client.getHost(), 
								channelName, targetNick, reason);

	_server->sendToChannel(channelName, kickMsg, -1);

	channel->removeMember(target->getFd());
	channel->removeOperator(target->getFd());
	return "";
}

static size_t	strToSizeT(std::string limit)
{
	if (limit.empty())
		return (0);

	size_t	val = 0;
	for (size_t i = 0; i < limit.size(); ++i)
	{
		if (limit[i] < '0' || limit[i] > '9')
			return (0);
		val = val * 10 + (limit[i] - '0');
	}
	return (val);
}

std::string	Commands::mode(Client &client, Message &msg)
{
	if (!client.isRegistered())
		return ("");

	std::string	nickname = "*";
	if (client.hasNick())
		nickname = client.getNick();

	if (msg.params.empty())
	{
		_server->sendNumeric(client.getFd(), "461", nickname, "MODE", "Not enough parameters");
		return ("");
	}

	const std::string channelName = msg.params[0];
	Channel *channel = _server->findChannel(channelName);
	if (!channel)
		return ERR_NOSUCHCHANNEL(_server->getServerName(), nickname, channelName);

	if (msg.params.size() == 1)
	{
		// build a string like <channel> <modes> [key] [limit]
		std::string	flags = channel->getModeFlags();
		std::string	modeParams = channelName + " " + flags;
		if (channel->hasKey())
			modeParams += " " + channel->getKey();
		if (channel->isUserLimited())
		{
			size_t	limit = channel->getUserLimit();
			std::string	limitstr;
			while (limit > 0)
			{
				char	c = char('0' + (limit % 10));
				limitstr.insert(limitstr.begin(), c);
				limit /= 10;
			}
			if (limitstr.empty())
				limitstr = "0";
			modeParams += " " + limitstr;
		}

		_server->sendNumeric(client.getFd(), "324", nickname, modeParams, "");
		return "";
	}

	if (!channel->isOperator(client.getFd()))
	{
		_server->sendNumeric(client.getFd(), "482", nickname, channelName, "You're not channel operator");
		return ("");
	}

	const std::string			modeStr = msg.params[1];
	bool						adding = true;
	char						addingChar = '+';
	size_t						paramIndex = 2;
	std::string					appliedModes;
	std::vector<std::string>	appliedParams;

	for (size_t i = 0; i < modeStr.size(); i++)
	{
		char	m = modeStr[i];
		if (m == '+')
		{
			adding = true;
			addingChar = '+';
			continue;
		}
		if (m == '-')
		{
			adding = false;
			addingChar = '-';
			continue;
		}

		if (m == 'i')
		{
			channel->setInviteOnly(adding);
			appliedModes += addingChar;
			appliedModes += "i";
		}
		else if (m == 't')
		{
			channel->setTopicOp(adding);
			appliedModes += addingChar;
			appliedModes += "t";
		}
		else if (m == 'k')
		{
			if (adding)
			{
				if (paramIndex >= msg.params.size())
				{
					_server->sendNumeric(client.getFd(), "461", nickname, "MODE", "Not enough parameters");
					return ("");
				}
				const std::string	key = msg.params[paramIndex++];
				channel->setKey(key);
				appliedModes += "+k";
				appliedParams.push_back(key);
			} else {
				channel->setKey("");
				appliedModes += "-k";
			}
		}
		else if (m == 'l')
		{
			if (adding)
			{
				if (paramIndex >= msg.params.size())
				{
					_server->sendNumeric(client.getFd(), "461", nickname, "MODE", "Not enough parameters");
					return ("");
				}
				size_t	limit = strToSizeT(msg.params[paramIndex++]);
				if (limit == 0)
				{
					_server->sendNumeric(client.getFd(), "461", nickname, "MODE", "Not enough parameters");
					return ("");
				}
				channel->setUserLimit(limit);
				appliedModes += "+l";

				size_t		temp = limit;
				std::string	limitStr;
				while (temp > 0)
				{
					char	c = char('0' + (temp % 10));
					limitStr.insert(limitStr.begin(), c);
					temp /= 10;
				}
				appliedParams.push_back(limitStr);
			} else {
				channel->setUserLimit(0);
				appliedModes += "-l";
			}
		}
		else if (m == 'o')
		{
			if (paramIndex >= msg.params.size())
			{
				_server->sendNumeric(client.getFd(), "461", nickname, "MODE", "Not enough parameters");
				return ("");
			}

			const std::string	targetNick = msg.params[paramIndex++];

			Client	*target = _server->findClientByNick(targetNick);
			if (!target)
			{
				_server->sendNumeric(client.getFd(), "401", nickname, targetNick, "No such nick/channel");
				return ("");
			}
			if (!channel->isMember(target->getFd()))
			{
				_server->sendNumeric(client.getFd(), "441", nickname, targetNick + " " + channelName, "They aren't on that channel");
				return ("");
			}

			if (adding)
				channel->addOperator(*target);
			else
				channel->removeOperator(target->getFd());

			appliedModes += addingChar;
			appliedModes += "o";
			appliedParams.push_back(targetNick);
		} else {
			std::string	modeChar(1, m);
			_server->sendNumeric(client.getFd(), "472", nickname, modeChar, "is unknown mode char to me");
		}
	}
	if (appliedModes.empty())
		return ("");

	// broadcast mode to channel members
	std::string	prefix = _server->getClientPrefix(client);
	std::string	line = ":" + prefix + " MODE " + channelName + " " + appliedModes;

	for (size_t	i = 0; i < appliedParams.size(); ++i)
		line += " " + appliedParams[i];
	line += "\r\n";
	_server->sendToChannel(channelName, line, -1);
	return ("");
}

std::string Commands::sendFile(Client &client, Message &msg)
{
	if (!client.isRegistered())
		return ("");

	std::string	nickname = "*";
	if (client.hasNick())
		nickname = client.getNick();
	
	if (msg.params.size() < 3)
	{
		_server->sendNumeric(client.getFd(), "461", nickname, "SEND", "Not enough parameters");
		return ("");
	}

	std::string	target = msg.params[0];
	std::string	filename = msg.params[1];
	std::string	filesize = msg.params[2];

	// don't send to self
	if (strcasecmp_irc(target, nickname))
	{
		_server->sendNumeric(client.getFd(), "461", nickname, "SEND", "Cannot send file to yourself");
		return ("");
	}

	// check valid file
	std::ifstream	file(filename.c_str());
	if (!file.good())
	{
		_server->sendNumeric(client.getFd(), "461", nickname, "SEND", "File not found or cannot be accessed");
		return ("");
	}
	file.close();

	Client	*targetClient = _server->findClientByNick(target);
	if (!targetClient)
	{
		_server->sendNumeric(client.getFd(), "401", nickname, target, "No such nick/channel");
		return ("");
	}

	size_t	size = 0;
	for (size_t i = 0; i < filesize.size(); ++i)
	{
		if (filesize[i] < '0' || filesize[i] > '9')
		{
			_server->sendNumeric(client.getFd(), "461", nickname, "SEND", "Invalid size");
			return ("");
		}
		size *= 10;
		size += (filesize[i] - '0');
	}

	FileTransfer	&filetransfer = _server->getFileTransfer();
	if (!filetransfer.sendFile(client.getFd(), targetClient->getFd(), filename, size))
	{
		_server->sendNumeric(client.getFd(), "461", nickname, "SEND", "Cannot create file session");
		return ("");
	}

	std::string	prefix = _server->getClientPrefix(client);
	std::string	message = ":" + prefix + " PRIVMSG " + target + " :" +
				"[FILE] " + client.getNick() + " wants to send '" + filename +
				"' (" + filesize + " bytes). Use: ACCEPT " + client.getNick() +
				" " + filename + "\r\n";

	_server->answerClient(targetClient->getFd(), message);
	return "";
}

std::string Commands::acceptFile(Client &client, Message &msg)
{
	if (!client.isRegistered())
		return ("");

	std::string	nickname = "*";
	if (client.hasNick())
		nickname = client.getNick();
	
	if (msg.params.size() < 2)
	{
		_server->sendNumeric(client.getFd(), "461", nickname, "ACCEPT", "Not enough parameters");
		return ("");
	}

	std::string	sender = msg.params[0];
	std::string	filename = msg.params[1];

	Client	*senderClient = _server->findClientByNick(sender);
	if (!senderClient)
	{
		_server->sendNumeric(client.getFd(), "401", nickname, sender, "No such nick/channel");
		return ("");
	}

	FileTransfer	&filetransfer = _server->getFileTransfer();
	if (!filetransfer.acceptFile(senderClient->getFd(), client.getFd(), filename))
	{
		_server->sendNumeric(client.getFd(), "461", nickname, "ACCEPT", "No pending file session");
		return ("");
	}

	std::string	prefixSender = _server->getClientPrefix(*senderClient);
	std::string	prefixReceiver = _server->getClientPrefix(client);
	std::string	toSender = ":" + prefixReceiver + " PRIVMSG " + sender + " :File transfer accepted, sending " + filename + "\r\n";
	std::string	toReceiver = ":" + prefixSender + " PRIVMSG " + client.getNick() + " :File transfer started, receiving " + filename + "\r\n";

	_server->answerClient(senderClient->getFd(), toSender);
	_server->answerClient(client.getFd(), toReceiver);

	filetransfer.startSending(*_server, senderClient->getFd());

	return "";
}
