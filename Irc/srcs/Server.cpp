#include "../includes/Server.hpp"
#include "../includes/Commands.hpp"
#include "../includes/Message.hpp"
#include "../includes/Colors.hpp"
#include "../includes/Reply.hpp"
#include "../includes/File.hpp"
#include "../includes/Bot.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cctype>

volatile sig_atomic_t g_shutdown = 0;

// helper func for case insensitive comparaison
static bool strcasecmp_irc(const std::string &a, const std::string &b)
{
	if (a.length() != b.length())
		return false;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (std::tolower(a[i]) != std::tolower(b[i]))
			return false;
	}
	return true;
}

Server::Server(const std::string &port, const std::string &password)
: _serverName("ircserv"), _portStr(port), _port(0), _password(""), _status(1),
_listenFd(-1), _pollFds(), _clients(), _bot("bot"), _fileTransfers()
{
	initServer(password);
	serverLoop();
}

Server::~Server()
{
	std::map<int, Client>::iterator it = _clients.begin();
	while (it != _clients.end()) {
		close(it->first);
		++it;
	}

	if (_listenFd >= 0)
		close(_listenFd);
}

std::string Server::getServerName() const
{
	return (_serverName);
}

std::string Server::getPassword() const
{
	return (_password);
}

std::map<int, Client>	&Server::getClients()
{
	return (_clients);
}

std::map<std::string, Channel>	&Server::getChannels()
{
	return (_channels);
}

void	Server::initServer(const std::string &password)
{
	std::cout << BOLDCYAN << "Initializing server..." << RESET << std::endl;
	try {
		initPort();
		_password = validatePassword(password);
		initSocket();
		std::cout << BOLDGREEN << "Port is: " << _port << std::endl;
		std::cout << "Password is: " << _password << RESET << std::endl;
		
		// _bot.joinChannel(*this, "#general");
		// std::cout << BOLDGREEN << "Bot joined #general" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Server initialization error: " << e.what() << std::endl;
	}
}

void	Server::initPort()
{
	_port = validatePort(_portStr);
}

void	Server::initSocket()
{
	_listenFd = socket(AF_INET, SOCK_STREAM, 0);
	if (_listenFd < 0)
		throw(std::runtime_error("failed to initialize listenFd socket"));

	int opt = 1;
	if (setsockopt(_listenFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
		throw(std::runtime_error("failed to set socket opt"));

	struct sockaddr_in addr;
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // qui set a 0.0.0.0
	addr.sin_port = htons(_port);

	if (bind(_listenFd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		throw(std::runtime_error("failed to bind sockaddr struct to listenFd"));

	if (listen(_listenFd, SOMAXCONN) < 0)
		throw(std::runtime_error("failed to listen to listenFd"));

	if (fcntl(_listenFd, F_SETFL, O_NONBLOCK) < 0)
		throw(std::runtime_error("failed to set listenFd to non-blocking"));

	struct pollfd pfd;
	pfd.fd = _listenFd;
	pfd.events = POLLIN; // ready for read
	pfd.revents = 0;

	_pollFds.push_back(pfd); // add pfd as first member inside the pollfds vector
}

void	Server::serverLoop()
{
	struct sigaction sa = {};
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) < 0)
		throw std::runtime_error("failed to set signal handler");
	signal(SIGPIPE, SIG_IGN);
	while (g_shutdown == 0 && _status == 1)
	{
		int	main_poll = poll(&_pollFds[0], _pollFds.size(), -1);
		if (main_poll < 0)
		{
			if (errno == EINTR)
				continue;
			throw(std::runtime_error("fatal whule polling fds"));
		}

		for (size_t i = 0; i < _pollFds.size(); ++i)
		{
			struct pollfd	&pfd = _pollFds[i];

			if (pfd.revents == 0)
				continue;

			if (pfd.fd == _listenFd && (pfd.revents & POLLIN))
				addConnection();
			else
				handleEvent(i);
		}
	//boucle sur les fd
	}
}

void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_shutdown = 1;
	}
}

void	Server::addConnection()
{
	while (1)
	{
		struct sockaddr_in	clientAddr;
		socklen_t	addrLen = sizeof(clientAddr);

		int	clientFd = accept(_listenFd, (struct sockaddr*)&clientAddr, &addrLen);
		if (clientFd < 0)
		{
			if (errno != EAGAIN && errno != EWOULDBLOCK)
				std::cerr << "accept() error: " << strerror(errno) << std::endl;
			break;
		}

		if (fcntl(clientFd, F_SETFL, O_NONBLOCK) < 0)
		{
			std::cerr << "fcntl failed on client fd" << std::endl;
			close(clientFd);
			continue;
		}

		_clients.insert(std::make_pair(clientFd, Client(clientFd)));

		struct pollfd	pfd;
		pfd.fd = clientFd;
		pfd.events = POLLIN;
		pfd.revents = 0;
		_pollFds.push_back(pfd);

		std::cout << "New client connected on fd" << clientFd << std::endl;
	}
}


void	Server::handleEvent(int index)
{
	struct pollfd	&pfd = _pollFds[index];

	if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL))
	{
		removeConnection(pfd.fd);
		return;
	}

	std::map<int, Client>::iterator	it = _clients.find(pfd.fd);
	if (it == _clients.end())
	{
		removeConnection(pfd.fd);
		return;
	}

	Client	&client = it->second;

	if (pfd.revents & POLLIN)
	{
		char	buff[512];
		// read into buff the readbuff of the client
		while (1)
		{
			ssize_t	rec_bytes = recv(pfd.fd, buff, 512, 0);
			if (rec_bytes > 0)
				client.getReadBuff().append(buff, rec_bytes);
			else if (rec_bytes == 0)
			{
				std::cout << "Client disconnected on fd" << pfd.fd << std::endl;
				removeConnection(pfd.fd);
				return;
			} else {
				if (errno == EAGAIN || errno == EWOULDBLOCK) 
					break;
				else
				{
					std::cerr << "recv failed on fd " << pfd.fd << std::endl;
					removeConnection(pfd.fd);
					return;
				}
			}
		}

		// Process IRC commands from the read buffer
		if (!client.getReadBuff().empty())
		{
			// if buffer is file transfer and not cmd
			bool isFileTransfer = _fileTransfers.handleData(*this, pfd.fd, client.getReadBuff());
			if (!isFileTransfer)
				processCRLF(client, pfd.fd);
		}
	}

	// send contents of clients writebuffer
	if (pfd.revents & POLLOUT)
	{
		std::string &out = client.getWriteBuff();
		while (!out.empty())
		{
			ssize_t	sent_bytes = send(pfd.fd, out.c_str(), out.size(), 0);
			if (sent_bytes > 0)
				out.erase(0, sent_bytes);
			else
			{
				if (errno == EAGAIN || errno == EWOULDBLOCK) 
					break;
				else
				{
					std::cerr << "send failed on fd " << pfd.fd << std::endl;
					removeConnection(pfd.fd);
					return;
				}
			}
		}

		if (out.empty())
			pfd.events &= ~POLLOUT;
	}
}

void	Server::processCRLF(Client &client, int fd)
{
	std::string	&clientBuff = client.getReadBuff();
	// std::cout << "READING BUFFER: " << clientBuff << std::endl;
	size_t	crlf = clientBuff.find("\r\n");
	size_t	lf = clientBuff.find("\n");
	size_t	delim = std::string::npos;
	size_t	delimLen = 0;


	// NEEDED FOR COMPATIBILITY ACROSS CRLF AND LF ONLY CLIENTS
	if (crlf != std::string::npos && (lf == std::string::npos || crlf <= lf))
	{
		delim = crlf;
		delimLen = 2;
	}
	else if (lf != std::string::npos)
	{
		delim = lf;
		delimLen = 1;
	}
	
	while (delim != std::string::npos)
	{
		std::string	line = clientBuff.substr(0, delim);
		clientBuff = clientBuff.substr(delim + delimLen);
		
		// find next LF/CRLF
		crlf = clientBuff.find("\r\n");
		lf = clientBuff.find("\n");
		delim = std::string::npos;
		
		if (crlf != std::string::npos && (lf == std::string::npos || crlf <= lf))
		{
			delim = crlf;
			delimLen = 2;
		}
		else if (lf != std::string::npos)
		{
			delim = lf;
			delimLen = 1;
		}

		if (line.empty())
			continue;

		// remove trailing \r
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);

		try {
			Message	msg = parseMessage(line);
			
			// DEBUG 
			std::cout << "command: " << msg.command << std::endl;
			if (!msg.params.empty())
			{
				for (size_t i = 0; i < msg.params.size(); i++)
					std::cout << "params: " << msg.params[i] << std::endl;
			}
			if (!msg.remaining.empty())
				std::cout << "remaining: " << msg.remaining << std::endl;

			if (!client.isRegistered())
			{
				if (msg.command == "CAP")
				{
					if (!msg.params.empty() && msg.params[0] == "LS")
						answerClient(fd, "CAP * LS :");
					else if (!msg.params.empty() && msg.params[0] == "END")
					{
						;
					}
					continue;
				}
				else if (msg.command == "NICK" || msg.command == "USER" || msg.command == "PASS")
				{
					// Use Commands class for registration commands
					handleCommand(client, fd, msg);
				}
				else
				{
					// if command exists but requires registration
					if (msg.command == "JOIN" || msg.command == "PART" || msg.command == "PRIVMSG" ||
						msg.command == "TOPIC" || msg.command == "KICK" || msg.command == "INVITE" ||
						msg.command == "MODE" || msg.command == "QUIT" || msg.command == "PING" ||
						msg.command == "PONG" || msg.command == "NAMES" || msg.command == "LIST" ||
						msg.command == "WHO" || msg.command == "WHOIS")
					{
						answerClient(fd, ERR_NOTREGISTERED(_serverName, "*"));
					}
					else
					{
						// truly unknown cmd
						answerClient(fd, ERR_UNKNOWNCOMMAND(_serverName, "*", msg.command));
					}
				}
			}
			else
				handleCommand(client, fd, msg);
		} catch (const std::exception &e) {
			// no error thrown from msg for the moment, to check later
			std::cout << "Message parsing error: " << e.what() << std::endl;
		}
	}

}

void	Server::handleCommand(Client &client, int fd, Message &msg)
{
	Commands	commandHub(this);
	std::string	cmd = msg.command;

	std::string	answer = commandHub.getAnswer(client, msg);
	if (!answer.empty())
		answerClient(fd, answer);
}

void	Server::answerClient(int fd, const std::string &answer)
{
	// ici on repond au client avec le message en format crlf dans le buffer
	std::map<int, Client>::iterator it = _clients.find(fd);
	if (it == _clients.end())
	{
		std::cerr << "Couldn't find client to send the answer" << std::endl;
		return;
	}

	// prepare writing answer into client buffer
	Client	&client = it->second;

	// append crlf if needed
	if (answer.size() >= 2 && answer.substr(answer.size() - 2) == "\r\n")
		client.getWriteBuff().append(answer);
	else
	{
		client.getWriteBuff().append(answer);
		client.getWriteBuff().append("\r\n");
	}

	// set fd to POLLOUT
	std::vector<struct pollfd>::iterator itp = _pollFds.begin();
	while (++itp != _pollFds.end())
	{
		if (itp->fd == fd)
		{
			itp->events |= POLLOUT;
			break;
		}
	}
}

void	Server::removeConnection(int fd)
{
	removeClientChannels(fd);

	std::map<int, Client>::iterator it = _clients.find(fd);
	if (it != _clients.end())
		_clients.erase(it);

	for (std::vector<struct pollfd>::iterator itp = _pollFds.begin(); itp != _pollFds.end(); ++itp)
	{
		if (itp->fd == fd)
		{
			_pollFds.erase(itp);
			break;
		}
	}

	close(fd);
}

int	Server::validatePort(const std::string &port)
{
	if (port.empty())
		throw std::runtime_error("Invalid port: " + _portStr);

	int p = std::atoi(port.c_str());

	if (p != 0 && p >= 1024 && p <= 49151)
		return (p);
	else
		throw std::runtime_error("Invalid port: " + _portStr);
}

std::string	Server::validatePassword(const std::string &pwd)
{
	if (pwd.empty() || pwd.size() < 1)
		throw std::runtime_error("Invalid password");
	return(pwd);
}

void	Server::sendToChannel(const std::string &channelName, const std::string &message, int exceptionFd)
{
	std::map<std::string, Channel>::iterator	it = _channels.find(channelName);

	if (it == _channels.end())
		return;

	std::vector<Client*> members = it->second.getMembers();
	for (std::vector<Client*>::iterator mit = members.begin(); mit != members.end(); ++mit)
	{
		Client	*curr = *mit;
		int	mfd = curr->getFd();
		if (exceptionFd != -1 && exceptionFd == mfd)
			continue; // skips exception fd
		answerClient(mfd, message);
	}
}

void	Server::removeClientChannels(int fd)
{
	for (std::map<std::string, Channel>::iterator it = _channels.begin(); it != _channels.end(); )
	{
		Channel	&channel = it->second;
		channel.removeMember(fd);
		channel.removeOperator(fd);

		if (channel.isEmpty())
		{
			std::map<std::string, Channel>::iterator	cit = it;
			it++;
			_channels.erase(cit);
		}
		else
			it++;
	}
}

std::string	Server::getClientPrefix(const Client &client) const
{
	std::string	nick = "*";
	std::string	user = "user";
	std::string	host = "localhost";

	if (!client.getNick().empty())
		nick = client.getNick();
	if (!client.getUser().empty())
		user = client.getUser();
	if (!client.getHost().empty())
		host = client.getHost();

	std::string	clientPrefix = nick + "!" + user + "@" + host;
	return (clientPrefix);
}

Client* Server::findClientByNick(const std::string &nick)
{
	std::map<int, Client>::iterator it = _clients.begin();
	while (it != _clients.end())
	{
		// case insensitive nickname comparaison
		if (strcasecmp_irc(it->second.getNick(), nick))
			return &(it->second);
		it++;
	}
	return (NULL);
}

Channel* Server::findOrCreateChannel(const std::string &channelName)
{
	// Cherche si le channel existe déjà
	std::map<std::string, Channel>::iterator it = _channels.find(channelName);

	if (it != _channels.end()) {
		// Le channel existe, retourne un pointeur vers celui-ci
		return &(it->second);
	}

	// Le channel n'existe pas, on le crée
	_channels[channelName] = Channel(channelName);
	return &(_channels[channelName]);
}

Channel* Server::findChannel(const std::string &channelName)
{
	std::map<std::string, Channel>::iterator it = _channels.find(channelName);

	if (it != _channels.end())
		return &(it->second);

	return NULL;
}

void	Server::registerClient(Client &client, int fd)
{
	std::cout << "Registering client" << std::endl;
	if (client.isRegistered())
		return;

	if (!_password.empty() && !client.hasPass())
		return;

	if (!client.hasNick() || !client.hasUser())
		return;

	client.setIsRegistered(true);

	const std::string nickname = client.getNick();
	const std::string username = client.getUser();
	const std::string hostname = client.getHost();

	// WELCOME SEQUENCE using Reply.hpp
	answerClient(fd, RPL_WELCOME(_serverName, nickname, username, hostname));

	std::cout << "Client registered: " << nickname << " (fd " << fd << ")" << std::endl;
}

void	Server::sendNumeric(int fd, const std::string &code, const std::string &target,
							const std::string &params, const std::string &remaining)
{
	std::string	reply = ":" + _serverName + " " + code + " " + target;
	if (!params.empty())
		reply += " " + params;
	if (!remaining.empty())
		reply += " :" + remaining;
	reply += "\r\n";
	answerClient(fd, reply);
}

void	Server::removeChannel(const std::string &channelName)
{
	std::map<std::string, Channel>::iterator it = _channels.find(channelName);
	if (it != _channels.end()) {
		_channels.erase(it);
		std::cout << "Channel " << channelName << " has been removed" << std::endl;
	}
}

void	Server::sendRawBytes(int fd, std::string chunk)
{
	std::map<int, Client>::iterator	it = _clients.find(fd);
	if (it == _clients.end())
	{
		std::cerr << "File transfer: Client not found for fd" << fd << std::endl;
		return;
	}

	Client &client = it->second;
	client.getWriteBuff().append(chunk);

	for (std::vector<struct pollfd>::iterator itp = _pollFds.begin(); itp != _pollFds.end(); ++itp)
	{
		if (itp->fd == fd)
		{
			itp->events |= POLLOUT;
			break;
		}
	}
}

Bot	&Server::getBot()
{
	return _bot;
}

const Bot	&Server::getBot() const
{
	return _bot;
}

FileTransfer	&Server::getFileTransfer()
{
	return _fileTransfers;
}

