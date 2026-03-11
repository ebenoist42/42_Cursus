/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:04:24 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 11:07:02 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& other)
{
	if ( this != &other)
	{
		AForm::operator=(other);
		this-> target = other.target;
	}
	return *this;
}
RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	check_signed(executor);
	std::cout << "* driling noises * \n";
	if(std::rand() % 2 == 0)
		std::cout << getTarjet() << " has been robotized ! \n";
	else
		std::cout << "The robotomy failed ! \n";
}

const std::string& RobotomyRequestForm::getTarjet() const
{
	return target;
}