/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:21:41 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/13 13:53:04 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <string>
#include <iostream>
#include <limits>

class Span {
	
	public :
		Span (unsigned int N);
		Span (const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void addNumber(int N);
		int shortestSpan()const;
		int longestSpan()const;
	private :
		unsigned int N_max;
		std::vector<int> N_array; 
};

#endif