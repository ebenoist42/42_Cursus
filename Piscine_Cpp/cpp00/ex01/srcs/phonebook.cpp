/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:37:56 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/21 12:02:00 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include <iomanip>

static std::string	troncstr(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::displaycontacts() const
{
	if(!_index)
	{
		std::cout << "Please add a contact before trying to display the contacts" << std::endl;
		return;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|    Index |First name| Last name| Nickname |" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if(i >= _index)
			break;
		std::cout << "|" << std::setw(10) << std::right << i + 1
				  << "|" << std::setw(10) << std::right << troncstr(_contacts[i].getFirstName())
				  << "|" << std::setw(10) << std::right << troncstr(_contacts[i].getLastName())
				  << "|" << std::setw(10) << std::right << troncstr(_contacts[i].getNickName()) << "|" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
}

PhoneBook::PhoneBook()
{
	_index = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::addcontact()
{
	std::string input;
	Contact new_contact;
	
	while(1)
	{
		std::cout << "Entrer First Name" << std::endl << ">";
		if(!std::getline(std::cin, input))
		{
			std::cout << "Error\nEOF detected." << std::endl;
			exit(0);
		}
		new_contact.setFirstName(input);
		if(input != "")
			break;
		std::cout << "Vous n'avez pas entrée le First name, réessayez." << std::endl;
	}
	while(1)
	{
		std::cout << "Entrer Last Name" << std::endl << ">";
		if(!std::getline(std::cin, input))
		{
			std::cout << "Error\nEof detected." << std::endl;
			exit(0);
		}
		new_contact.setLastName(input);
		if(input != "")
			break;
		std::cout << "Vous n'avez entrée le Last name, réessayez." << std::endl;
	}
	while(1)
	{
		std::cout << "Entre Nickname" << std::endl << ">";
		if(!std::getline(std::cin, input))
		{
			std::cout << "Error\nEOF detected." << std::endl;
			exit(0);
		}
		new_contact.setNickname(input);
		if(input != "")
			break;
		std::cout << "Vous n'avez pas entrée le Nick name, réessayez." << std::endl;
	}
	while(1)
	{
		std::cout << "Entrer Phone Number" << std::endl << ">";
		if(!std::getline(std::cin, input))
		{
			std::cout << "Error\nEof detected." << std::endl;
			exit(0);
		}
		new_contact.setPhoneNumber(input);
		if(input != "")
			break;
		std::cout << "Vous n'avez pas entrée le Numero de tel, réessayez." << std::endl;
	}
	while(1)
	{
		std::cout << "Entrer Darkest secret" << std::endl << ">";
		if(!std::getline(std::cin, input))
		{
			std::cout << "Error\nEof detected." << std::endl;
			exit(0);
		}
		if(input != "")
			break;
		std::cout << "Vous n'avez pas entrée de numero, réessayez." << std::endl;
	}
	_contacts[_index % 8] = new_contact;
	_index++;
}

void	PhoneBook::displayonecontact(int index) const
{
	std::cout << "First name : " << _contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last name : " << _contacts[index - 1].getLastName() << std::endl;
	std::cout << "Nickname : " << _contacts[index - 1].getNickName() <<  std::endl;
	std::cout << "Phone Number : " << _contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret " << _contacts[index - 1].getDarkestSecret() << std::endl;
}

int	PhoneBook::getindex() const
{
	return (_index);
}
