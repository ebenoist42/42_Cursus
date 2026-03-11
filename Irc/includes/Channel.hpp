#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"
#include <map>
#include <vector>

class Channel {
	public:
		Channel();
		Channel(const std::string &name);
		~Channel();

		// Getters
		std::string	getName() const;
		std::string	getTopic() const;
		// Setters
		void setTopic(const std::string &newTopic);
		// Members management
		void	addMember(Client &client);
		void	addOperator(Client &client);
		void	addInvited(Client &client);
		void	removeMember(int fd);
		void	removeOperator(int fd);
		void	removeInvited(int fd);
		bool	isMember(int fd) const;
		bool	isOperator(int fd) const;
		bool	isInvited(int fd) const;
		bool	isEmpty() const;
		std::vector<Client*>	getMembers();

		// Functions needed for mode command
		void	setInviteOnly(bool flag);
		void	setTopicOp(bool flag);
		void	setUserLimit(size_t limit);
		void	setKey(const std::string &key);

		bool	isInviteOnly() const;
		bool	isTopicOp() const;
		bool	isUserLimited() const;
		bool	hasKey() const;

		size_t				getUserLimit() const;
		const std::string	&getKey() const;

		std::string	getModeFlags() const;
	private:
		std::string					_name;
		std::string					_topic;
		std::string					_pwd;
		std::map<int, Client*>		_invitees;		// invitation list for mode
		std::map<int, Client*>		_members;		// fd -> Client
		std::map<int, Client*>		_operators;		// fd -> Client

		// Modes
		bool	_modeInviteOnly;
		bool	_modeTopicOp;
		bool	_modeHasKey;
		bool	_modeHasLimit;
		size_t	_userLimit;
};

#endif