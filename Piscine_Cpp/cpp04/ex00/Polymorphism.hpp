/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:58:23 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/08 13:51:53 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP

#include <iostream>

class Animal{

public : 
		Animal();
		virtual ~Animal();
		Animal& operator=(const Animal& other);
		Animal (const Animal& other);
		
		virtual void makeSound() const;
		std::string getType() const;

protected :
		std::string type;

};

class Dog : public Animal {

public: 
	Dog();
	virtual ~Dog();
	Dog& operator=(const Dog& other);
	Dog(const Dog& other);

	void makeSound() const;
	
protected:
};


class Cat : public Animal {

public: 
	Cat();
	virtual ~Cat();
	Cat& operator=(const Cat& other);
	Cat(const Cat& other);

	void makeSound() const;
	
protected:
};

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	virtual ~WrongAnimal();

	virtual void makeSound() const;
	std::string getType() const;
};

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	virtual ~WrongCat();

	void makeSound() const;
};



#endif