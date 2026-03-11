/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:25:16 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/20 13:54:04 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::setFirstName(const std::string& firstname)
{
	_firstname = firstname;
}
void Contact::setLastName(const std::string& lastname)
{
	_lastname = lastname;
}
void Contact::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}
void Contact::setPhoneNumber(const std::string& phonenumber)
{
	_phonenumber = phonenumber;
}
void Contact::setDarkestSecret(const std::string& secret)
{
	_darkestsecret = secret;
}
const	std::string& Contact::getFirstName() const
{
	return _firstname;
}

const	std::string& Contact::getLastName() const
{
	return _lastname;
}

const	std::string& Contact::getNickName() const
{
	return _nickname;
}

const	std::string& Contact::getPhoneNumber() const
{
	return _phonenumber;
}

const	std::string& Contact::getDarkestSecret() const
{
	return _darkestsecret;
}