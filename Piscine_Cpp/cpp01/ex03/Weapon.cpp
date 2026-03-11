/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:09:45 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 15:47:50 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	this->type = type;
}

const std::string& Weapon::getType(void) const
{
	return type;
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}

Weapon::~Weapon() {}