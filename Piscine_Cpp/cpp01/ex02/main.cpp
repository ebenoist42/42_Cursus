/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:00:58 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 13:26:43 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main ()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	
	std::cout << "The memory address of the string variable : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringPTR      : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      : " << &stringREF << std::endl;
	std::cout << "The value of the string variable          : " << brain << std::endl;
	std::cout << "The value pointed to by stringPTR         : " <<*stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;
}