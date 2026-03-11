#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <signal.h>
#include "Client.hpp"
#include "Message.hpp"
#include "Channel.hpp"
#include "Bot.hpp"
#include "File.hpp"

class Server {
	public:
		Server(const std::string &port, const std::string &password);
		~Server();

		std::string						getServerName() const;
		std::string						getPassword() const;
		std::map<int, Client>			&getClients();
		std::map<std::string, Channel>	&getChannels();

		void		initServer(const std::string &password); // -> va appeller tous les initiateurs en private, puis fait une boucle while(_status == alive)
		Channel*	findOrCreateChannel(const std::string &channelName);
		Channel*	findChannel(const std::string &channelName);
		void		sendToChannel(const std::string &channelName, // answers channel
								const std::string &message, int exceptionFd);
		
		std::string	getClientPrefix(const Client &client) const; // gets formatted client prefix for responses
		void		answerClient(int fd, const std::string &answer);
		void		sendRawBytes(int fd, std::string chunk);
		void		removeChannel(const std::string &channelName);
		Client*		findClientByNick(const std::string &nick);

		void	sendNumeric(int fd, const std::string &code,
						const std::string &target,
						const std::string &params,
						const std::string &remaining);

		Bot				&getBot();
		const Bot		&getBot() const;
		FileTransfer	&getFileTransfer();

	private:
		std::string	_serverName;
		std::string	_portStr;
		int			_port;
		std::string	_password;
		int			_status;
		int			_listenFd;

		std::vector<struct pollfd>		_pollFds;
		std::map<int, Client>			_clients;
		std::map<std::string, Channel>	_channels;  // nom du channel -> Channel

		Bot				_bot;
		FileTransfer	_fileTransfers;		void	serverLoop();
		void	initPort();
		void	initSocket();
		void	addConnection();
		void	handleEvent(int index);
		void	removeConnection(int fd);

		int			validatePort(const std::string &port);
		std::string	validatePassword(const std::string &pwd);

		void	processCRLF(Client &client, int fd);
		void	handleCommand(Client &client, int fd, Message &msg);

		void	removeClientChannels(int fd);

		void	registerClient(Client &client, int fd);

		Server();
		Server(const Server &copy);
		Server &operator=(const Server &rhs);
};

void	signal_handler(int sig);
