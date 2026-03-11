/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 09:51:40 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/29 10:23:09 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
Intern::Intern(const Intern& other)
{
	(void)other;
}
Intern::~Intern(){}

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string FormName, std::string target)
{
	std::string FormNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (*creators[3])(const std::string& ) ={
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};
	
	for(int i = 0; i < 3; i++)
	{
		if(FormName == FormNames[i])
		{
			std::cout << "Intern creates " << FormName << std::endl;
			return creators[i](target);
		}
	}
	std::cerr << "Error name : " << FormName << " doesn't exist.\n";
	throw std::runtime_error("Intern cannot create unknown form");
	return NULL;
}