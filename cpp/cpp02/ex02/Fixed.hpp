/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:51:09 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/03 13:46:20 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	public:
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);
		static Fixed& min(Fixed& a, Fixed& b);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed(const int fixed_point);
		Fixed (float f);
		Fixed ();
		Fixed(const Fixed&other);
		Fixed &operator=(const Fixed& other);
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator--(int);
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator++();

	private :
		int value;
		static const int _fractionalBits = 8;;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif