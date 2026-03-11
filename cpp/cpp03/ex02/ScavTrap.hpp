/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:51:34 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/06 18:44:43 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public: 
	ScavTrap(const std::string& name);
	~ScavTrap();
	ScavTrap (const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	
	void	attack (const std::string& taget);
	void	guardGate();

private:
	
};

#endif