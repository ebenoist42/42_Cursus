/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:29:42 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 15:55:20 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon{
	
	public:
		Weapon(const std::string& type);
		~Weapon ();
		const std::string& getType(void)const;
		void setType(const std::string& type);
	private:
		std::string type;
};

#endif