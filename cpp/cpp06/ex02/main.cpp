/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:46:25 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/05 16:15:15 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	int i = rand() % 3;
	if(i == 0)
		return new A;
	else if(i == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p: A \n";
	else if (dynamic_cast<B*>(p))
		std::cout << "p: B \n";
	else if (dynamic_cast<C*>(p))
		std::cout << "p: C \n";
	else
		std::cout << "Unknown Type\n";
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";\
		return;
	}
	catch (...) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B\n";
		return;
	}
	catch (...) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C\n";
		return;
	}
	catch (...) {}
	std::cout << "Unknown Type\n";
}

int main ()
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test numero : " << i << std::endl;
		Base* ptr = generate();
		std::cout << "Identify with pointer: ";
		identify(ptr);
		std::cout << "Identify with reference: ";
		identify(*ptr);
		delete ptr;
		std::cout << "-----" << std::endl;
	}
	return 0;
}