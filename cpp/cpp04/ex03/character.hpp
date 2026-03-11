/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:19:02 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/09 11:44:52 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Icharacter.hpp"

class Character : public ICharacter {
private:
	std::string name;
	AMateria*	inventory[4];

public:
	Character(std::string const & name);
	Character(const Character& other);
	~Character();
	Character& operator=(const Character& other);
	
	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif