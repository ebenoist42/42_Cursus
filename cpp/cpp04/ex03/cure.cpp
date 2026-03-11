/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:39:07 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/09 11:57:52 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other.type) {}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
