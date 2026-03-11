/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:29:56 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 15:55:30 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
	
	private :
		std::string name;
		Weapon& arme;
	public :
		HumanA(const std::string& name, Weapon& arme);
		~HumanA();
		void attack();
};

#endif