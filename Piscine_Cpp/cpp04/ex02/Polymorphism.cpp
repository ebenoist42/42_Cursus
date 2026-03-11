/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:58:16 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/08 15:33:20 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default construtor called "<<std::endl;
}

Animal::~Animal() 
{
	std::cout << "Animal default destrutor called "<<std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if(this != &other)
		type = other.type;
	std::cout << "Animal operator= called "<<std::endl;
	return *this;
}

Animal::Animal (const Animal& other)
{
	*this = other;
	std::cout << "Animal copy constructor called\n";
}

void Animal::makeSound() const
{
	std::cout << " Aniaml Sound \n";
}

std::string Animal::getType() const
{
	return type;
}

Dog::Dog()
{
	this -> type = "Dog";
	std::cout << "Dog default construtor called "<<std::endl;
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this-> type = other.type;
	std::cout << "Dog copy constructeur called "<<std::endl;
	brain = new Brain(*other.brain);
}

void Dog::makeSound() const
{
		std::cout << "Wouf Wouf!" << std::endl;
}

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default construtor called "<<std::endl;
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destrutor called "<<std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Cat copy constructeur operator called" << std::endl;
	brain = new Brain(*other.brain);

}

void Cat::makeSound() const
{
	std::cout << "Miaouuu Miaouuu!\n";
}

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	std::cout << "Type: " << type << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) 
{
	if (this != &other) {
		type = other.type;
	}
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const 
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const 
{
	return type;
}

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meooo! Meooo! (wrong cat)" << std::endl;
}
