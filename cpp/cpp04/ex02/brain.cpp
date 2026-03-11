/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:54:26 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/08 15:33:51 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default contructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		std::cout << "Brain assignement operator called\n";
		for(int i = 0; i < 100; ++i)
			random[i] = other.random[i];
	}
	return *this;
}

Brain::Brain(const Brain& other)
{
	std::cout << " Brain copy constructor called\n";
	for(int i = 0; i < 100; ++i)
			random[i] = other.random[i];
}
