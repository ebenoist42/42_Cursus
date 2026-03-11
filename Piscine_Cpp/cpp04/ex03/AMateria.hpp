/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:41 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/09 11:25:26 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	AMateria& operator=(const AMateria& other);
	AMateria(const AMateria& other);
	virtual ~AMateria();
	
	std::string const & getType() const; // Retourne le type de materia
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif