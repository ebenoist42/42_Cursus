#ifndef BOT_HPP
#define BOT_HPP

#include <string>
#include <set>
#include <map>
#include "Client.hpp"
#include "Message.hpp"

class	Server;
class	Channel;

struct WordleGame {
	std::string	word;
	int			attempts;
	bool		active;

	WordleGame() : word(""), attempts(0), active(false) {}
};

class	Bot {
	public:
		Bot(const std::string &nick);
		~Bot();

		const std::string	&getNick() const;

		void	joinChannel(Server &server, const std::string &channel);
		void	leaveChannel(Server &server, const std::string &channel);
		bool	isInChannel(const std::string &channel) const;

		Message	botCreateMessage(Message &message);
		void	onMessage(Server &server, Client &client, Message &originalMessage);
		void	onChannelMessage(Server &server, Client &client, const std::string &channel, Message &originalMessage);

	private:
		std::string							_nickname;
		std::set<std::string>				_channels;
		std::map<std::string, WordleGame>	_wordleGames; // structure nickname->game

		std::string	doCommand(Client &client, Message &message);

		typedef std::string (Bot::*BotFunction)(Client&, Message&);

		static const int				_numBot = 11;
		static const std::string		_botTab[_numBot];
		static const BotFunction		_botFunctions[_numBot];
		static const int				_wordCount = 1637;
		static const std::string		_wordleWords[_wordCount];

		std::string	help(Client &client, Message &message);
		std::string	ping(Client &client, Message &message);
		std::string	echo(Client &client, Message &message);
		std::string	reverse(Client &client, Message &message);
		std::string	roll(Client &client, Message &message);
		std::string	eightball(Client &client, Message &message);
		std::string	choose(Client &client, Message &message);
		std::string	hug(Client &client, Message &message);
		std::string	insult(Client &client, Message &message);
		std::string	wordle(Client &client, Message &message);
		std::string	guess(Client &client, Message &message);

		std::string	checkWordle(const std::string &guess, const std::string &answer);
};

#endif