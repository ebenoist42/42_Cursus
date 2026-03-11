/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:58:30 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/08 13:53:16 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"


int main()
{
    std::cout << "--- TEST ANIMAL ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // Doit afficher le son du chat
    j->makeSound(); // Doit afficher le son du chien
    meta->makeSound(); // Son générique d’animal

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- TEST WRONG ANIMAL ---" << std::endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wi = new WrongCat();

    std::cout << wi->getType() << std::endl;

    wi->makeSound();
    wmeta->makeSound();

    delete wi;
    delete wmeta;

    return 0;
}