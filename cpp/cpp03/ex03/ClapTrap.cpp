/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:58:12 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 18:58:42 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
	std::cout << "ClapTrap " << name << " was created" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " was destroyed" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& other)
{
	name = other.name;
	Hit_points = other.Hit_points;
	Energy_points = other.Energy_points;
	Attack_damage = other.Attack_damage;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other)
{
	name = other.name;
	Hit_points = other.Hit_points;
	Energy_points = other.Energy_points;
	Attack_damage = other.Attack_damage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if(Energy_points <= 0 || Hit_points <= 0)
	{
		std::cout << name << "doesn't have energy point " << std::endl;
		return;
	}
	else
	{
		Energy_points--;
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " 
		<< Attack_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	Hit_points -= amount;
	if(Hit_points < 0)
		Hit_points = 0;
	std::cout << "ClapTrap " << name << " take damage and have " << Hit_points << " Hit points"  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_points <= 0)
	{
		std::cout << name << " is dead and can't be repaired!" << std::endl;
		return;
	}
	if(Energy_points <= 0)
		std::cout << name << " can't be repaired, no a lot energy points, game over" << std::endl;
	else
	{
		Hit_points += amount;
		std::cout << "ClapTrap " << name << " won " << amount << " hit points, an have now "
		<< Hit_points << " hit_points " << std::endl;
	}
}
