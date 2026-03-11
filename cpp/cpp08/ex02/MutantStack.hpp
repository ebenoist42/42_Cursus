/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:44 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/15 14:04:10 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_HPP
#define MUTAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <string>
#include <iostream>
#include <limits>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{

private : 

public :
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator iterator;
	MutantStack(){}
	MutantStack(const MutantStack &other): stack(other){}
	MutantStack& operator= (const MutantStack &other){
		stack::operator=(other);
		return *this;
	}
	~MutantStack(){}
	iterator begin(){
		return this->c.begin();
	}
	iterator end(){
		return this->c.end();
	}
};

#endif