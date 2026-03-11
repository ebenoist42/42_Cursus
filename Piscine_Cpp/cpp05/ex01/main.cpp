/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:05:18 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 10:52:49 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	try {
		Bureaucrat a ("Sylvie", 5);	
		Form CAF ("Demande AREF", 10, 8);
		std::cout << "Sylvie a bien remplis votre document ?? : " << CAF.getIsSigned() << std::endl;
		a.signForm(CAF);
		CAF.beSigned(a);
		std::cout << "Sylvie a bien remplie votre demande AREF ?? : " << CAF.getIsSigned() << std::endl;
		}
	catch (std::exception &e){
		std::cout <<  e.what() << std::endl;}
		std::cout << "--------------------------------------------------------------------\n";
	try {
		Bureaucrat b ("Jean", 50);
		Form Alloc ("Prime activitee", 10, 9);
		std::cout << "Jean a bien remplis votre document ?? : " << Alloc.getIsSigned() << std::endl;
		b.signForm(Alloc);
		Alloc.beSigned(b);
		std::cout << "Jean a bien remplis votre document ?? : " << Alloc.getIsSigned() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "Jean n'est pas assez qualifie pour remplis et/ou executer votre aide" << e.what() << std::endl;
	}
}