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

#include "AForm.hpp"

AForm::AForm(const std::string name, int GradeToSigne, int GradeToExecute) : name(name), 
		issigned(false), GradeToSigne(GradeToSigne), GradeToExecute(GradeToExecute)
{
	if (GradeToSigne < 1 || GradeToExecute < 1)
		throw GradeToHighException();
	if (GradeToSigne > 150 || GradeToExecute > 150)
		throw GradetoLowException();
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other) {
		this->issigned = other.issigned;
	}
	return *this;
}

AForm::AForm(const AForm &other): name(other.name), issigned(other.issigned), 
		 GradeToSigne(other.GradeToSigne) ,GradeToExecute(other.GradeToExecute){}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream &opera, const AForm &other)
{
	opera << other.getName() << ", Form " << (other.getIsSigned() ? "signed" : "not signed")
	   << ", requires grade " << other.getToSign()
	   << " to sign and " << other.getToExec() << " to execute.";
	   return opera;
}

const std::string&	AForm::getName() const
{
	return name;
}

int			AForm::getToSign() const
{
	return GradeToSigne;
}

int			AForm::getToExec() const
{
	return GradeToExecute;
}

bool		AForm::getIsSigned() const
{
	return issigned;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > GradeToSigne)
		throw GradetoLowException();
	issigned = true;
}

void AForm::check_signed(Bureaucrat const &executor) const
{
	if(issigned == false)
		throw AForm::FormNotSignedExecption();
	if(executor.getGrade() > this->GradeToExecute)
		throw AForm::GradetoLowException();
}