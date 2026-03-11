/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:55:34 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/21 11:34:15 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include "../includes/contact.hpp"


static	void search_func(PhoneBook Phonebook)
{
	std::string input;
	int number;
	Phonebook.displaycontacts();
	if(!Phonebook.getindex())
		return;
	while(1)
	{
		std::cout << "Entrer the index of the contact thah you want to display :";
		if(!std::getline(std::cin, input))
		{
			std::cout << "EOF detected. End of programme" << std::endl;
			exit(0);
		}
		std::istringstream iss(input);
		if (iss >> number && iss.eof())
		{
			if(number > Phonebook.getindex() || number < 1)
			{
				std::cout << "Please enter a correct index" << std::endl;
				continue;
			}
			Phonebook.displayonecontact(number);
			break;
		}
		
	}
}

int main (void)
{
	PhoneBook Phonebook;
	std::string input;
	while(1)
	{
		std::cout << "Entrer your commande commande [ADD, SEARCH, EXIT]" << std::endl;
		std::cout << ">";
		if(!std::getline(std::cin, input))
		{
			std::cout << "EOF detected. End of program." << std::endl;
			return(0);
		}
		else if (input == "EXIT")
			break;
		else if (input == "ADD")
			Phonebook.addcontact();
		else if (input == "SEARCH")
			search_func(Phonebook);
	}
	std::cout << "Thank's have nice day !" << std::endl;
	return(0);
}