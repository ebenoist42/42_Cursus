/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:51:24 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/03 13:51:09 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ()
{
	this-> value = 0;
}

Fixed::Fixed(const int n)
{
	this-> value = n << _fractionalBits;
}

Fixed::Fixed(float f)
{
	this-> value = roundf(f * (1 << _fractionalBits)); // roundf retrourne un entier a 
	//l'arrondi le plus proche, car multiplier avec un float normale on aurait encore une virgule, ronf plus precis que de caster en int 
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
	value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this-> value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits( void ) const
{
	return this-> value;
}

void Fixed::setRawBits( int const raw )
{
	this-> value = raw;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a > b)
		return a;
	return b;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this-> value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this-> value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this-> value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this-> value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this-> value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this-> value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	float result = this->toFloat() + other.toFloat();
	return Fixed(result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	float result = this->toFloat() - other.toFloat();
	return Fixed(result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	float result = this->toFloat() * other.toFloat();
	return Fixed (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Division par 0 impossible, remplacée par 1" << std::endl;
		return *this;
	}
	float result = this->toFloat() / other.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	value--;
	return (temp);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	value++;
	return (temp);
}

Fixed Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator++()
{
	value++;
	return *this;
}
