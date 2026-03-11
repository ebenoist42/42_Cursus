/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:49 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/09 11:54:51 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Icharacter.hpp"

AMateria::AMateria(const AMateria& other) : type(other.type)
{
	// type est déjà copié automatiquement par le compilateur dans le constructeur de copie
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}
