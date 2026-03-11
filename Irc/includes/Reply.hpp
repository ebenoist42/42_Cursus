#pragma once

// GENERAL MESSAGE
# define	RPL_WELCOME(servername, nick, user, host) (":" + servername + " 001 " + nick + " :Welcome to the Internet Relay Network " + nick + "!" + user + "@" + host)
# define	ERR_UNKNOWNCOMMAND(servername, client, command) (":" + servername + " 421 " + client + " " + command + " :Unknown command")
# define	ERR_NEEDMOREPARAMS(servername, client, command) (":" + servername + " 461 " + client + " " + command + " :Not enough parameters")
# define	ERR_NOTREGISTERED(servername, client) (":" + servername + " 451 " + client + " :You have not registered")
# define	client_id(nick, user, host) (":" + nick + "!" + user + "@" + host)
/*  ****************************************************************************** */
/*  ******************************** client messages ******************************* */
/*  ****************************************************************************** */

// client MESSAGE ERRORS
# define	ERR_NOPRIVILEGES(servername, nick) (":" + servername + " 481 " + nick + " :Permission Denied- You're not an IRC operator")
# define	ERR_ALREADYREGISTERED(servername, client) (":" + servername + " 462 " + client + " :Unauthorized command (already registered)")

// PASS MESSAGE ERRORS
# define	ERR_PASSWDMISMATCH(servername, client) (":" + servername + " 464 " + client + " :Password incorrect")

// NICK MESSAGE ERRORS
# define	NICK(old_nick, user, host, nick) (":" + old_nick + "!" + user + "@" + host + " NICK " + nick)
# define	ERR_NONICKNAMEGIVEN(servername, client) (":" + servername + " 431 " + client + " :No nickname given")
# define	ERR_ERRONEUSNICKNAME(servername, client, nick) (":" + servername + " 432 " + client + " " + nick + " :Erroneous nickname")
# define	ERR_NICKNAMEINUSE(servername, client, nick) (":" + servername + " 433 " + client + " " + nick + " :Nickname is already in use")

// PRIVMSG/NOTICE ERRORS
# define	ERR_NOTEXTTOSEND(servername, nick) (":" + servername + " 412 " + nick + " :No text to send")

/*  PING OR PONG   */
# define	PING(client_id, param) (client_id + " PING :" + param)
# define	PONG(client_id, param) (client_id + " PONG :" + param)

/*  OPERATOR messages   */
# define	RPL_YOUREOPER(servername, nick) (":" + servername + " 381 " + nick + " :You are now an IRC operator")

/*  QUIT   */
# define	QUIT(client_id, reason) (client_id + " QUIT :" + reason)

/*  Kill	*/
# define	KILL(source, reason) ("You have been disconeected from the server by " + source + ", because " + reason)
# define	KILL_WOREASON(source) ("You have been disconeected from the server by " + source)

/*  ****************************************************************************** */
/*  ******************************** CHANNEL messages ******************************* */
/*  ****************************************************************************** */
# define	ERR_NOSUCHCHANNEL(servername, nick, channel) (":" + servername + " 403 " + nick + " " + channel + " :No such channel")
# define	ERR_USERNOTINCHANNEL(servername, nick, target, channel) (":" + servername + " 441 " + nick + " " + target + " " + channel + " :They aren't on that channel")
# define	ERR_NOTONCHANNEL(servername, nick, channel) (":" + servername + " 442 " + nick + " " + channel + " :You're not on that channel")
# define	ERR_USERONCHANNEL(servername, nick, target, channel) (":" + servername + " 443 " + nick + " " + target + " " + channel + " :is already on channel")
# define	ERR_BADCHANMASK(servername, nick, channel) (":" + servername + " 476 " + nick + " " + channel + " :Bad Channel Mask")

# define	ERR_NOSUCHNICK(servername, nick, target) (":" + servername + " 401 " + nick + " " + target + " :No such nick/channel")

/*  Join	*/
# define	JOIN(nick, user, host, channel) (":" + nick + "!" + user + "@" + host + " JOIN " + channel)
# define	CREATEDCHANNEL(channel) (channel + " channel created")
# define	ERR_INVITEONLYCHAN(servername, nick, channel) (":" + servername + " 473 " + nick + " " + channel + " :Cannot join channel (+i)")
# define	ERR_BADCHANNELKEY(servername, nick, channel) (":" + servername + " 475 " + nick + " " + channel + " :Cannot join channel (+k)")
# define	ERR_CHANNELISFULL(servername, nick, channel) (":" + servername + " 471 " + nick + " " + channel + " :Cannot join channel (+l)")
# define	ERR_TOOMANYCHANNELS(servername, nick, channel) (":" + servername + " 405 " + nick + " " + channel + " :You have joined too many channels")

/*  Invite  */
# define	RPL_INVITING(servername, nick, target, channel) (":" + servername + " 341 " + nick + " " + target + " " + channel)
# define	INVITE(nick, user, host, target, channel) (":" + nick + "!" + user + "@" + host + " INVITE " + target + " :" + channel)

/*  Names   */
# define	RPL_NAMREPLY(servername, nick, channel, clients) (":" + servername + " 353 " + nick + " = " + channel + " :" + clients)
# define	RPL_ENDOFNAMES(servername, nick, channel) (":" + servername + " 366 " + nick + " " + channel + " :End of /NAMES list")

/*  KICK	*/
# define	KICK(nick, user, host, channel, target, reason) (":" + nick + "!" + user + "@" + host + " KICK " + channel + " " + target + " :" + reason)
/*  PART	*/
# define	PART(nick, user, host, channel, reason) (":" + nick + "!" + user + "@" + host + " PART " + channel + " :" + reason)
/*  Topic   */
# define	RPL_TOPIC(servername, nick, channel, topic) (":" + servername + " 332 " + nick + " " + channel + " :" + topic)
# define	RPL_NOTOPIC(servername, nick, channel) (":" + servername + " 331 " + nick + " " + channel + " :No topic is set")
# define	TOPIC(nick, user, host, channel, topic) (":" + nick + "!" + user + "@" + host + " TOPIC " + channel + " :" + topic)
/*  Modes   */
# define	ERR_CHANOPRIVSNEEDED(servername, nick, channel) (":" + servername + " 482 " + nick + " " + channel + " :You're not channel operator")
# define	MODE(nick, user, host, target, modes, params) (":" + nick + "!" + user + "@" + host + " MODE " + target + " " + modes + (params.empty() ? "" : " " + params))
# define	RPL_UMODEIS(servername, nick, modes) (":" + servername + " 221 " + nick + " " + modes)
# define	ERR_KEYSET(servername, nick, channel) (":" + servername + " 467 " + nick + " " + channel + " :Channel key already set")
# define	RPL_CHANNELMODEIS(servername, nick, channel, modes) (":" + servername + " 324 " + nick + " " + channel + " " + modes)
# define	ERR_UNKNOWNMODE(servername, nick, modechar) (":" + servername + " 472 " + nick + " " + modechar + " :is unknown mode char to me")

/*  PRIVMSG */
# define	PRIVMSG(nick, user, host, target, message) (":" + nick + "!" + user + "@" + host + " PRIVMSG " + target + " :" + message)
# define	NOTICE(nick, user, host, target, message) (":" + nick + "!" + user + "@" + host + " NOTICE " + target + " :" + message)
# define	RPL_AWAY(servername, nick, target, awaymsg) (":" + servername + " 301 " + nick + " " + target + " :" + awaymsg)
