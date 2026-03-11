/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:05:02 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 19:29:41 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this-> Hit_points = 100;
	this-> Energy_points = 50;
	this-> Attack_damage = 20;
	std::cout << "ScavTrap " << name << " was created" << std::endl;
	
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " was destroyed\n";
}

ScavTrap::ScavTrap (const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
	this->Hit_points = other.Hit_points;
	this->Energy_points = other.Energy_points;
	this->Attack_damage = other.Attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called for " << name << std::endl;
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
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