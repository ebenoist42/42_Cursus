/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:58:14 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/21 12:09:17 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	if(ac != 2){
		std::cout << "Error: could not open file. \n";
		return (0);
	}
	try {
		BitcoinExchange Exchange(av[1]);
		Exchange.open();
		Exchange.parse();
	}
	catch(std::exception &e){
		std::cout << e.what();
	}
	
}