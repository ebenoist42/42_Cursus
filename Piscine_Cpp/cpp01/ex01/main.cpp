/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:45:42 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 11:48:08 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie* horde = zombieHorde(5, "Zombiiie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
}