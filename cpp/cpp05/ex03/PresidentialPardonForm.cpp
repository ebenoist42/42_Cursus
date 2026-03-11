/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:02:36 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 11:06:53 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (const std::string& target) : 
AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &other) :
AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm () {}

const std::string& PresidentialPardonForm::getTarget() const 
{
	return target;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	check_signed(executor);
	std::cout << getTarget() << " has been pardonned by Zaphod Beeblerox " << std::endl;
}