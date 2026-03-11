/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:22 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 19:49:06 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
	std::cout << "DiamondTrap constructor called for " << name << std::endl;

}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << name << std::endl;

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
		std::cout << "DiamondTrap assignment operator called for " << name << std::endl;
	}
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	this-> name = other.name;
	std::cout << "DiamondTrap copy constructor called for " << name << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::highFivesGuys()
{
	std::cout << this->name << " wants a high five!\n";
}

void DiamondTrap::attack(const std::string& target)
{
	if(Energy_points <= 0 || Hit_points <= 0)
	{
		std::cout << name << "doesn't have energy point " << std::endl;
		return;
	}
	else
	{
		Energy_points--;
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " 
		<< Attack_damage << " points of damage!" << std::endl;
	}
}