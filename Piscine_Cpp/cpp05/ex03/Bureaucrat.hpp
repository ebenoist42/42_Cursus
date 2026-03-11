/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:05:12 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 10:25:25 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat{

public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	~Bureaucrat();
	
	const std::string& getName() const ;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	
	class GradeTooHighException : public std::exception{
		const char* what() const throw(){
		return "Grade is to hight !";
		}
	};
	class GradeTooLowException : public std::exception{
		const char* what() const throw(){
			return "Grade is to low !";
		}
	};
	void	signForm(AForm& Form);
	void	executeForm(AForm const &form) const;

private:
	const std::string name;
	int grade;
};

std::ostream& operator<<(std::ostream& opera, const Bureaucrat& a);

#endif 