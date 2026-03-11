/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:57:50 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/03 15:47:01 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	ClapTrap a("Bob");
	ClapTrap b("Yves");
	std::cout << std::endl;
	a.attack("Alice");
	b.takeDamage(5);
	std::cout << std::endl;
	b.beRepaired(3);
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
		a.attack("Alice");
	std::cout << std::endl;
	b.takeDamage(5);
	b.beRepaired(5);
	return 0;
}
