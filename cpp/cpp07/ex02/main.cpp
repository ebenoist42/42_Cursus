/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:07:48 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/08 17:15:55 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <iostream>
#include <string>
#include "Array.hpp"


int main() {
	std::cout << "TEST TABLEAU SIMPLE\n";
	Array<int> arr(10);
	arr[0] = 5;
	std::cout << arr[0] << std::endl;
	std::cout << "TEST TABLEAU CONST\n";
	const Array<int> tabConst (10);
	//tabConst[0] = 5; 
	std::cout << "TEST TABLEAU SIMPLE, INDEX > QUE TAB \n";
	Array<char> array (4);
	char letter[] = {'H','E','L','L','O'};
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = letter[i];
	try {
		for (unsigned int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;}
	catch (std::exception &e){
		std::cout << e.what()<< " Sorry try with smaller index\n";
	}
	return 0;
}