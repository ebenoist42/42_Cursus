/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:25:06 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/20 13:51:08 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Contact
{
private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;

public:
	Contact();
	~Contact();
	void setFirstName(const std::string &firstname);
	void setLastName(const std::string &lastname);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phonenumber);
	void setDarkestSecret(const std::string &darksecret);

	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickName() const;
	const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;
};

#endif