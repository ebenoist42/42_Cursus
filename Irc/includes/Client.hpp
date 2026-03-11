#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {
	public:
		Client();
		Client(int fd);
		Client(const Client &copy);
		Client &operator=(const Client &rhs);
		~Client();

		int			getFd() const;
		std::string	&getReadBuff();
		std::string	&getWriteBuff();

		const std::string	&getNick() const;
		const std::string	&getUser() const;
		const std::string	&getReal() const;
		const std::string	&getHost() const;

		void	setNick(std::string const &nickname);
		void	setUser(std::string const &username);
		void	setReal(std::string const &realname);
		void	setHost(std::string const &hostname);

		bool	hasNick() const;
		bool	hasPass() const;
		bool	hasUser() const;
		bool	isRegistered() const;

		void	setHasNick(bool flag);
		void	setHasPass(bool flag);
		void	setHasUser(bool flag);
		void	setIsRegistered(bool flag);


	private:
		int			_fd;
		std::string	_readBuff;
		std::string	_writeBuff;

		// client vars
		std::string	_nickname;
		std::string	_username;
		std::string	_realname;
		std::string	_hostname;

		// flags for confirmity
		bool	_hasNick;
		bool	_hasPass;
		bool	_hasUser;
		bool	_isRegistered;

};

#endif