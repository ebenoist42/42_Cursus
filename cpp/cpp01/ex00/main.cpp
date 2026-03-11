/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:45:16 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 10:44:19 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	std::cout << "1er test, newZombie" << std::endl;
	Zombie* z = newZombie("CHUMP");
	z->announce();
	delete z;
	std::cout << "\n";
	std::cout << "2eme test, randomChump" << std::endl;
	randomChump("2eme");
	return(0);
}

