/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:11:33 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 10:39:17 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int GradeToSigne, int GradeToExecute) : name(name), 
		issigned(false), GradeToSigne(GradeToSigne), GradeToExecute(GradeToExecute)
{
	if (GradeToSigne < 1 || GradeToExecute < 1)
		throw GradeToHighException();
	if (GradeToSigne > 150 || GradeToExecute > 150)
		throw GradetoLowException();
}

Form& Form::operator=(const Form &other)
{
	if (this != &other) {
		this->issigned = other.issigned;
	}
	return *this;
}

Form::Form(const Form &other): name(other.name), issigned(other.issigned), 
		 GradeToSigne(other.GradeToSigne) ,GradeToExecute(other.GradeToExecute){}

Form::~Form() {}

std::ostream& operator<<(std::ostream &opera, const Form &other)
{
	opera << other.getName() << ", Form " << (other.getIsSigned() ? "signed" : "not signed")
	   << ", requires grade " << other.getToSign()
	   << " to sign and " << other.getToExec() << " to execute.";
	   return opera;
}

const std::string&	Form::getName() const
{
	return name;
}

int			Form::getToSign() const
{
	return GradeToSigne;
}

int			Form::getToExec() const
{
	return GradeToExecute;
}

bool		Form::getIsSigned() const
{
	return issigned;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > GradeToSigne)
		throw GradetoLowException();
	issigned = true;
}