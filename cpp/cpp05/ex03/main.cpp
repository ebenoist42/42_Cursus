/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:05:18 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/03 11:57:56 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));
	Intern NewIntern;
	AForm* shrub = NewIntern.makeForm("shrubbery creation", "tree");
	AForm* pardon = NewIntern.makeForm("presidential pardon", "some dog");
	AForm* robot = NewIntern.makeForm("robotomy request", "wall-e");
	try{
		Bureaucrat boss ("Boss", 1);
		
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		std::cout << "\n";
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		std::cout << "\n";
		boss.signForm(*robot);
		boss.executeForm(*robot);
		std::cout << "\n";
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------INVALID FORM----------------\n";
	try{
		AForm* zero = NewIntern.makeForm("aide a vie", "qwerty");
		Bureaucrat boss ("b", 1);
		boss.signForm(*zero);
		boss.executeForm(*zero);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	delete shrub;
	delete robot;
	delete pardon;
	return 0;
}