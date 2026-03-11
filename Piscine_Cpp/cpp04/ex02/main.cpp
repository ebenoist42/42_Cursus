/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:58:30 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/08 16:44:31 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"
#include "brain.hpp"


int main()
{
    //Animal* test = new Animal(); impossible comm le veux l'exo
	std::cout << "--- CREATION TABLEAU ---" << std::endl;

    const int size = 4;
    Animal* animals[size];

    // 2 Dogs + 2 Cats
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- DESTRUCTION TABLEAU ---" << std::endl;

    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n--- TEST DEEP COPY ---" << std::endl;

    Dog dog1;
    Dog dog2 = dog1;    // Appelle le constructeur par copie → deep copy

    std::cout << "Fin du programme." << std::endl;
}