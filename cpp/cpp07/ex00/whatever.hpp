/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:56:01 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/07 17:02:25 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
T const& min (T const& x, T const &y)
{
	if (x < y)
		return x;
	else
		return y;
}

template <typename T>
T const& max (T const& x, T const& y)
{
	if (x > y)
		return x;
	else
		return y;
}

template <typename T>
void swap (T &x, T &y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

#endif