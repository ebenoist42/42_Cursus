/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:13 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/08 10:50:20 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
	
	public:
		DiamondTrap(const std::string &name);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& other);
		DiamondTrap(const DiamondTrap& other);
	
		void	highFivesGuys();
		void	attack (const std::string& taget);
		void	whoAmI();
	private:
		std::string name;
		
};

#endif