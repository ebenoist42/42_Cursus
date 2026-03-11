#include "../includes/Client.hpp"

Client::Client() : _fd(-1), _readBuff(), _writeBuff(),
_nickname(), _username(), _realname(), _hostname(),
_hasNick(false), _hasPass(false), _hasUser(false), _isRegistered(false)
{}

Client::Client(int fd) : _fd(fd), _readBuff(), _writeBuff(),
_nickname(), _username(), _realname(), _hostname(),
_hasNick(false), _hasPass(false), _hasUser(false), _isRegistered(false)
{}

Client::Client(const Client &copy) : _fd(copy._fd), _readBuff(copy._readBuff), _writeBuff(copy._writeBuff),
_nickname(copy._nickname), _username(copy._username), _realname(copy._realname), _hostname(copy._hostname),
_hasNick(copy._hasNick), _hasPass(copy._hasPass), _hasUser(copy._hasUser), _isRegistered(copy._isRegistered)
{}

Client &Client::operator=(const Client &rhs)
{
	if (this != &rhs)
	{
		_fd = rhs._fd;
		_readBuff = rhs._readBuff;
		_writeBuff = rhs._writeBuff;

		_nickname = rhs._nickname;
		_username = rhs._username;
		_realname = rhs._realname;
		_hostname = rhs._hostname;

		_hasNick = rhs._hasNick;
		_hasPass = rhs._hasPass;
		_hasUser = rhs._hasUser;
		_isRegistered = rhs._isRegistered;
	}
	return (*this);
}

Client::~Client()
{}

// FD getters
int Client::getFd() const {
	return (_fd);
}

std::string &Client::getReadBuff() {
	return (_readBuff);
}

std::string &Client::getWriteBuff() {
	return (_writeBuff);
}

// User properties getters
const std::string	&Client::getNick() const
{
	return (_nickname);
}

const std::string	&Client::getUser() const
{
	return (_username);
}

const std::string	&Client::getReal() const
{
	return (_realname);
}

const std::string	&Client::getHost() const
{
	return (_hostname);
}

// User properties setters
void	Client::setNick(std::string const &nickname)
{
	_nickname = nickname;
}

void	Client::setUser(std::string const &username)
{
	_username = username;
}

void	Client::setReal(std::string const &realname)
{
	_realname = realname;
}

void	Client::setHost(std::string const &hostname)
{
	_hostname = hostname;
}

// User bools getters
bool	Client::hasNick() const
{
	return (_hasNick);
}

bool	Client::hasPass() const
{
	return (_hasPass);
}

bool	Client::hasUser() const
{
	return (_hasUser);
}

bool	Client::isRegistered() const
{
	return (_isRegistered);
}

// User bools setters
void	Client::setHasNick(bool flag)
{
	_hasNick = flag;
}
void	Client::setHasPass(bool flag)
{
	_hasPass = flag;
}
void	Client::setHasUser(bool flag)
{
	_hasUser = flag;
}
void	Client::setIsRegistered(bool flag)
{
	_isRegistered = flag;
}
