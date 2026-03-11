/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:38:24 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/28 17:21:08 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac != 2){
		std::cout << "AC can't bigger 2\n";
		return 0;
	}
	try{
		RPN calcule(av[1]);
		calcule.ParseAndFill();}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}