/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:57:33 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 17:18:00 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->name = name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap " << name << " was created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " was destroyed\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap (other)
{
	std::cout << "FragTrap assignement operator called for " << name << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if ( this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignement operator called for " << name << std::endl;
	return(*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " Want a high Fives!\n";
}

