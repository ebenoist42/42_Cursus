#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

struct Message {
	std::string					literalStr;
	std::string					prefix;
	std::string					command;
	std::string					remaining;
	std::vector<std::string>	params;
};

Message	parseMessage(const std::string &literal);

#endif