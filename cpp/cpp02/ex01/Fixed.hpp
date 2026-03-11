/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:29:39 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/03 10:49:39 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	public :
		Fixed(const int fixed_point);
		Fixed (float f);
		Fixed ();
		Fixed(const Fixed&other);
		Fixed &operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;
	private :
		int value;
		static const int _fractionalBits = 8;;
};

std::ostream& operator<<(std::ostream &os, const Fixed &obj);

#endif