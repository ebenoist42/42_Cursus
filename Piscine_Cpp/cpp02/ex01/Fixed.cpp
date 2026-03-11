/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:29:49 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/03 10:49:21 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ()
{
	this-> value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	this-> value = n << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f)
{
	this-> value = roundf(f * (1 << _fractionalBits)); // roundf retrourne un entier a 
	//l'arrondi le plus proche, car multiplier avec un float normale on aurait encore une virgule, ronf plus precis que de caster en int 
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return(float)this-> value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this-> value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called " << std::endl;
	value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &other)
		this-> value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called " << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return this-> value;
}

void Fixed::setRawBits( int const raw )
{
	this-> value = raw;
}
