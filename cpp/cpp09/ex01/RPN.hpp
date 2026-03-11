/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:38:15 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/28 17:01:39 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <string>
#include <limits>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <limits.h>
#include <stdexcept>
#include <cstdlib>

class RPN {
	private :
		std::stack<int> Array;
		std::string av;
	public : 
		RPN(const std::string &string);
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		void ParseAndFill();
		void Operation(int c);
};



#endif