#include "../includes/Channel.hpp"

Channel::Channel() : _name(""), _topic(""), _pwd(""),
_modeInviteOnly(false), _modeTopicOp(false), _modeHasKey(false), _modeHasLimit(false), _userLimit(0) {}

Channel::Channel(const std::string &name) : _name(name), _topic(""), _pwd(""),
_modeInviteOnly(false), _modeTopicOp(false), _modeHasKey(false), _modeHasLimit(false), _userLimit(0) {}

Channel::~Channel() {}

std::string	Channel::getName() const {
	return _name;
}

std::string	Channel::getTopic() const {
	return _topic;
}

void	Channel::setTopic(const std::string &newTopic) {
	_topic = newTopic;
}

bool	Channel::isEmpty() const {
	return _members.empty();
}

void	Channel::addMember(Client &client) {
	_members[client.getFd()] = &client;
}

void	Channel::addOperator(Client &client) {
	_operators[client.getFd()] = &client;
}

void	Channel::addInvited(Client &client) {
	_invitees[client.getFd()] = &client;
}

void	Channel::removeMember(int fd) {
	_members.erase(fd);
}

void	Channel::removeOperator(int fd) {
	_operators.erase(fd);
}

void	Channel::removeInvited(int fd) {
	_invitees.erase(fd);
}

bool	Channel::isMember(int fd) const {
	return _members.find(fd) != _members.end();
}

bool	Channel::isOperator(int fd) const {
	return _operators.find(fd) != _operators.end();
}

bool	Channel::isInvited(int fd) const {
	return _invitees.find(fd) != _invitees.end();
}

std::vector<Client*>	Channel::getMembers() {
	std::vector<Client*>	members;
	for (std::map<int, Client*>::iterator it = _members.begin(); it != _members.end(); ++it) {
		members.push_back(it->second);
	}
	return members;
}

// MODE functions

void	Channel::setInviteOnly(bool flag)
{
	_modeInviteOnly = flag;
}

void	Channel::setTopicOp(bool flag)
{
	_modeTopicOp = flag;
}

void	Channel::setUserLimit(size_t limit)
{
	if (limit == 0)
		_modeHasLimit = false;
	else
		_modeHasLimit = true;
	_userLimit = limit;
}

void	Channel::setKey(const std::string &key)
{
	if (key == "")
		_modeHasKey = false;
	else
		_modeHasKey = true;
	_pwd = key;
}

bool	Channel::isInviteOnly() const
{
	return (_modeInviteOnly);
}

bool	Channel::isTopicOp() const
{
	return (_modeTopicOp);
}

bool	Channel::isUserLimited() const
{
	return (_modeHasLimit);
}

bool	Channel::hasKey() const
{
	return (_modeHasKey);
}

size_t	Channel::getUserLimit() const
{
	return (_userLimit);
}

const std::string	&Channel::getKey() const
{
	return (_pwd);
}

std::string	Channel::getModeFlags() const
{
	std::string	flags = "+";
	if (_modeInviteOnly)
		flags += "i";
	if (_modeTopicOp)
		flags += "t";
	if (_modeHasKey)
		flags += "k";
	if (_modeHasLimit)
		flags += "l";
	return (flags);
}

