/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:45:41 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 10:34:15 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
	this->name = name;
}

Zombie::~Zombie ()
{
	std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::announce ()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}