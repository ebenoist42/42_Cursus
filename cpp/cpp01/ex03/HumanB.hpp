/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:30:20 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 15:55:25 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
	
	private:
		std::string name;
		Weapon* arme;
	public:
	HumanB(const std::string& name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon& arme);
};

#endif