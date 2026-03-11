/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:21:57 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/13 16:21:42 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main ()
{
	std::srand(std::time(NULL));
	std::cout << "MAIN  42:                              \n";
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;}
	catch(std::exception &e){
		std::cout << "Exception : " << e.what() << std::endl;}

	try{
		Span SmallArray(10);
		SmallArray.addNumber(1);
		SmallArray.addNumber(3);
		SmallArray.addNumber(15);
		std::cout << "The shortest span in SmallArray is : " << SmallArray.shortestSpan() << std::endl;
		std::cout << "The longest span in SmallArray is : " << SmallArray.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "Exception : " << e.what() << std::endl;}
		
	try{
		Span BigArray(10000);
		for(int i = 0; i < 10000; i++)
			BigArray.addNumber(std::rand());
		std::cout << "The shortest span in BigArray is : " << BigArray.shortestSpan() << std::endl;
		std::cout << "The longest span in BigArray is : " << BigArray.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << "Execption : " << e.what() << std::endl;}

}
