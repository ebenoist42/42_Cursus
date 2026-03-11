/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:30:08 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 15:48:02 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& arme)
	: arme(arme)
{
	this->name = name;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << arme.getType() << std::endl;
}

HumanA::~HumanA() {}