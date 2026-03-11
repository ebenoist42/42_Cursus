/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:11:24 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/18 15:08:24 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {

public: 

	Form(const std::string name, int GradeToSigne, int GradeToExecute);
	Form& operator=(const Form &other);
	Form(const Form &other);
	~Form();

	const std::string&	getName() const;
	int			getToSign() const;
	int			getToExec() const;
	bool		getIsSigned() const;
	void	beSigned(const Bureaucrat& bureaucrat);

	class GradeToHighException : public std::exception{
		const char* what() const throw(){
			return "Grade is too hight !";
		}
	};
	class GradetoLowException : public std::exception{
		const char * what() const throw(){
			return "Grade is too low !";
		}
	};
private:
	const std::string name;
	bool  issigned;
	const int GradeToSigne;
	const int GradeToExecute;
	
};

std::ostream& operator<<(std::ostream &opera, const Form &other);

#endif