/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:00:55 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/28 13:44:06 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "DEBUG : " << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put " <<
				"enough bacon in my burger! If you did, I wouldn’t be asking for more! " << std::endl;
	std::cout << std::endl;
}
		
void Harl::info (void)
{
	std::cout << "INFO : " << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put " <<
			"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}
void Harl::warning(void)
{
	std::cout << "WARNING : " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for " <<
					"years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}
void Harl::error (void)
{
	std::cout << "ERROR : " << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*funcs[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	for(int i = 0; i < 4; i++)
	{
		if(levels[i] == level)
			(this->*funcs[i])();
	}
}