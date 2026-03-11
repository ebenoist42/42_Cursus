/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:05:08 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/18 15:16:45 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : 
	name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException(); 
	this->grade = grade;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if(this != &other)
		grade = other.getGrade();
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if(grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

const std::string& Bureaucrat::getName() const 
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

std::ostream& operator<<(std::ostream& opera, const Bureaucrat& a)
{
	opera << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
	return opera;
}

void	Bureaucrat::signForm(Form& Form)
{
	try{
		Form.beSigned(*this);
		std::cout << this->getName() << " signed " << Form.getName() << std::endl;
	}
	catch ( std::exception &e){
		std::cout << this->getName() << " can't  sign " << Form.getName() 
		<< " because " << e.what() << std::endl;}
}
