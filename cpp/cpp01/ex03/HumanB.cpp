/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:30:33 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 15:48:08 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
{
	this->name = name;
	this->arme = NULL;
}

void	HumanB::attack() const
{
	if(arme)
			std::cout << name << " attacks with their " << arme->getType() << std::endl;
	else
		std::cout << name << " can't attack. He doesn't have weapon." << std::endl;
}

void	HumanB::setWeapon(Weapon& arme)
{
	this->arme = &arme;
}

HumanB::~HumanB() {}