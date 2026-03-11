#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "Message.hpp"
#include "Client.hpp"

class Server;  // Forward declaration

class Commands {
	public:
		Commands(Server *server);
		~Commands();
		std::string	getAnswer(Client &client, Message &msg);
	
	private:
		Server		*_server;
		typedef std::string (Commands::*CommandFunction)(Client&, Message&);
		
		static const int				_numCommands = 17;
		static const std::string		_commandsTab[_numCommands];
		static const CommandFunction	_commandsFunctions[_numCommands];

		bool	nicknameExists(const std::string &nickname);
		bool	isvalideNickname(const std::string &nickname);

		std::string	ping(Client &client, Message &msg);
		std::string	join(Client &client, Message &msg);
		std::string	part(Client &client, Message &msg);
		std::string	nick(Client &client, Message &msg);
		std::string	user(Client &client, Message &msg);
		std::string	pass(Client &client, Message &msg);
		std::string	topic(Client &client, Message &msg);
		std::string	privmsg(Client &client, Message &msg);
		std::string	notice(Client &client, Message &msg);
		std::string userhost(Client &client, Message &msg);
		std::string quit(Client &client, Message &msg);
		std::string invite(Client &client, Message &msg);
		std::string	kick(Client &client, Message &msg);
		std::string	mode(Client &client, Message &msg);

		std::string sendFile(Client &client, Message &msg);
		std::string acceptFile(Client &client, Message &msg);
};

#endif