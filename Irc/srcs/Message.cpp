#include "../includes/Message.hpp"

std::string	strToCap(std::string command)
{
	for (size_t i = 0; i < command.size(); ++i)
	{
		if (command[i] >= 'a' && command[i] <= 'z')
			command[i] -= 32;
	}
	return (command);
}

Message	parseMessage(const std::string &literal)
{
	Message	msg;
	msg.literalStr = literal;

	size_t	len = msg.literalStr.size();
	size_t	i = 0;

	// skip leading whitespace
	while (i < len && msg.literalStr[i] == ' ')
		i++;

	// checks if theres a : prefix
	if (msg.literalStr[i] == ':')
	{
		i++;
		size_t	prefix_start = i;

		// scan until end of word
		while (i < len && msg.literalStr[i] != ' ')
			i++;
		msg.prefix = msg.literalStr.substr(prefix_start, i - prefix_start);

		// skip whitespaces again
		while (i < len && msg.literalStr[i] == ' ')
		i++;
	}

	// parse command
	size_t	cmd_start = i;
	while (i < len && msg.literalStr[i] != ' ')
		i++;
	msg.command = msg.literalStr.substr(cmd_start, i - cmd_start);

	// parse params
	while (i < len)
	{
		// skip ws
		while (i < len && msg.literalStr[i] == ' ')
			i++;
		// break on reach end
		if (i >= len)
			break;

		// find prefix : -> substr everything left and break
		if (msg.literalStr[i] == ':')
		{
			i++;
			std::string	remaining = msg.literalStr.substr(i);
			msg.remaining = remaining;
			break;
		} else {
			size_t	param_start = i;
			while (i < len && msg.literalStr[i] != ' ')
				i++;
			msg.params.push_back(msg.literalStr.substr(param_start, i - param_start));
		}
	}

	// capitalize command to normalize
	msg.command = strToCap(msg.command);
	return (msg);
}
