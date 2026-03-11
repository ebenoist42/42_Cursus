/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:58:02 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 18:49:41 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap (const ClapTrap& other);
	ClapTrap& operator= (const ClapTrap& other);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
protected:
	std::string name;
	int Hit_points;
	int Energy_points;
	int Attack_damage;
};

#endif