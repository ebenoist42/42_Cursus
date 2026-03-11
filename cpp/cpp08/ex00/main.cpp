/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:14:00 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/15 14:12:47 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	try {
		std::vector<int>::iterator it = easyfind(v, 2);
		std::cout << "Found int: " << *it << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Int not found" << std::endl;
	}

	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	try {
		std::list<int>::iterator it = easyfind(l, 25);
		std::cout << "Found int in list: " << *it << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Int 25 not found in list..." << std::endl;
	}

	l.push_front(25);
	try {
		std::list<int>::iterator it = easyfind(l, 25);
		std::cout << "Now Int 25 is found : " << *it << "!\n";
	}
	catch (std::exception &e){
		std::cout << "Int not found\n";
	}

	return 0;
}
