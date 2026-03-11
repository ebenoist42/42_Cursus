/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:32:56 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/03 13:43:39 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if(ac == 2)
	{
		std::string string = av[1];
		ScalarConverter::convert(string);
	}
	else
		std::cout << "Number of params not good !\n";
	return(0);
}