/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:05:18 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/03 11:57:08 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));
	std::cout << "------------------Form-PresidentialPardonForm----------------------\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm form("un petit chien gentil ");
		std::cout << "\n--- Tentative d'execution sans signature ---\n";
		boss.executeForm(form);
		std::cout << "\n--- Signature du formulaire ---\n";
		boss.signForm(form);
		std::cout << "\n--- Execution avec un bon grade ---\n";
		boss.executeForm(form);
		std::cout << "\n--- Execution avec un grade trop bas ---\n";
		intern.executeForm(form);
	}
	catch (std::exception &e)
	{
	std::cerr << "Exception attrapée dans main : " << e.what() << std::endl;
	}
	std::cout << "------------------Form-RobotomyRequestForm----------------------\n";
	try
	{
		Bureaucrat boss("Boss 2", 1);
		Bureaucrat intern("Intern 2", 150);
		RobotomyRequestForm form2("Random Form");
		std::cout << "\n--- Tentative d'execution sans signature ---\n";
		boss.executeForm(form2);
		std::cout << "\n--- Signature du formulaire ---\n";
		boss.signForm(form2);
		std::cout << "\n--- Execution avec un bon grade 1er tentative---\n";
		boss.executeForm(form2);
		std::cout << "\n--- Execution avec un bon grade 2eme tentative---\n";
		boss.executeForm(form2);
		std::cout << "\n--- Execution avec un bon grade 3eme tentative---\n";
		boss.executeForm(form2);
		std::cout << "\n--- Execution avec un grade trop bas ---\n";
		intern.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception attrapée dans main : " << e.what() << std::endl;
	}
	std::cout << "------------------Form-ShrubberyCreationForm----------------------\n";
	try
	{
		Bureaucrat boss("Boss 3", 1);
		Bureaucrat intern("Intern 3", 150);
		ShrubberyCreationForm form3("Creation Arbre Noel");
		std::cout << "\n--- Tentative d'execution sans signature ---\n";
		boss.executeForm(form3);
		std::cout << "\n--- Signature du formulaire ---\n";
		boss.signForm(form3);
		std::cout << "\n--- Execution avec un bon grade ---\n";
		boss.executeForm(form3);
		std::cout << "\n--- Execution avec un grade trop bas ---\n";
		intern.executeForm(form3);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception attrapée dans main : " << e.what() << std::endl;
	}
	return 0;
}