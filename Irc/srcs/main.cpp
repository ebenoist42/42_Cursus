/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oben-ham <oben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:27:47 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/12/12 12:51:10 by oben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"
#include "../includes/Colors.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << RED << "Please Use: ./ircserv [port] [password]" << RESET << std::endl;
		return (1);
	}
	try
	{
		Server server(argv[1], argv[2]);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}

	return 0;
}
