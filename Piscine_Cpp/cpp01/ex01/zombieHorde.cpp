/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:13:17 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 11:45:04 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if(N < 1)
		return(NULL);
	try
	{
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].set_name_zombie(name);
		return (horde);
	}
	catch (std::bad_alloc&)
	{
		std::cerr << "Allocation failed." << std::endl;
		return(NULL);
	}
}