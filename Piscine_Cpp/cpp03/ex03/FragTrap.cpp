/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:57:33 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 19:50:55 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap " << name << " was created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " was destroyed\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap (other)
{
	this->Hit_points = other.Hit_points;
	this->Energy_points = other.Energy_points;
	this->Attack_damage = other.Attack_damage;
	std::cout << "FragTrap copy constructeur called for " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if ( this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap operator= called for " << name << std::endl;
	return(*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " Want a high Fives!\n";
}

