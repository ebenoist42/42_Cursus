/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:05:18 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/18 14:08:28 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	try {
		Bureaucrat a ("Sylvie", 17);	
		std::cout << "Voici le nom de la premiere Bureaucrat : " << a.getName() << " et sont grade : "<< a.getGrade()<< std::endl;
		a.incrementGrade();
		a.incrementGrade();	
		std::cout << "Premiere Augmentation de Sylvie, Bravo !\nNouveau grade : " << a.getGrade() << std::endl;
		std::cout << "On va augmenter au max Sylivie !!\n";
		for (int i = 0 ; i < 14; i++)
					a.incrementGrade();
		std::cout << "Deuxieme Augmentation de Sylvie, On ne peux pas mieux faire ! Bravo !\nNouveau grade : " << a.getGrade() << std::endl;
		std::cout << "____________________________________________________________________________________\n";
		std::cout << "Aller on va esseyer encore une Augmentation pour Sylvie ? " << std::endl;
		a.incrementGrade();
		std::cout << "Ca a marcher ???????????????????????????????????\n";
		}
	catch (std::exception &e){
		std::cout <<  e.what() << std::endl;}

	try{
		Bureaucrat c("Gisel", 139);
		std::cout << "\nMaintenant on voir " << c.getName() << " avec un grade de : " << c.getGrade() << std::endl;
		std::cout << "Retrogradage pour Gisel....\n";
		for (int i = 0; i < 10; i++)
				c.decrementGrade();
		std::cout << "Desole " << c.getName() << " Nouveau Grade : " << c.getGrade() << "....\n";
		}
	catch (std::exception &e){
		std::cout <<  e.what() << std::endl;}

	try{
		Bureaucrat e("Emma", 26);
		std::cout << e << std::endl;
	}
	catch (std::exception &e){
		std::cout << "ERR" << e.what()<< std::endl;
	}
	try{
		Bureaucrat d("Louis", 199);
	}
	catch (std::exception &e){
		std::cout << "Bureaucrat  + de 150 pas admis..." << e.what() << std::endl;}
}