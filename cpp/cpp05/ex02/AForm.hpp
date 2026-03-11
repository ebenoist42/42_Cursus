/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:11:24 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 11:01:11 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {

public: 

	AForm(const std::string name, int GradeToSigne, int GradeToExecute);
	AForm& operator=(const AForm &other);
	AForm(const AForm &other);
	virtual ~AForm();

	const std::string&	getName() const;
	int			getToSign() const;
	int			getToExec() const;
	bool		getIsSigned() const;
	void	beSigned(const Bureaucrat& bureaucrat);
	class FormNotSignedExecption : public std::exception{
		const char* what() const throw(){
			return "Form is not signed !";
		}
	};
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
	void check_signed(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const =0;

protected:
	const std::string name;
	bool  issigned;
	const int GradeToSigne;
	const int GradeToExecute;
};

std::ostream& operator<<(std::ostream &opera, const AForm &other);

#endif