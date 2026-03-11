/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:02:02 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 11:07:16 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), target(other.target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	check_signed(executor);
	std::ofstream ofs((target + "_shrubbery").c_str());
	if(!ofs)
		throw std::runtime_error("Cannot open file");
	ofs << "       /\\\n";
	ofs << "      /**\\\n";
	ofs << "     /****\\\n";
	ofs << "    /******\\\n";
	ofs << "   /********\\\n";
	ofs << "       ||\n";
	ofs << "       ||\n";
	ofs.close();
}