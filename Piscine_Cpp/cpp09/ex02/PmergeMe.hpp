/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:54:47 by ebenoist          #+#    #+#             */
/*   Updated: 2026/02/03 17:23:00 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
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
#include <string>
#include <limits.h>
#include <stdexcept>
#include <sys/time.h>
#include <cstdlib>

class PmergeMe{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator= (const PmergeMe &other);
	~PmergeMe();
	void	ParseDisplay(int ac, char **av);
	void	sortVector();
	void	sortDeqeu();
	void	CheckDisplay();

private:
	struct Element{
		int value;
		std::vector<int> small;

		bool operator<(const Element& other) const { return value < other.value; }
		bool operator<(int val) const { return value < val; }
	};
	double _vecTime;
	double _deqTime;
	template<typename ContainerElements>
	void	fordJohnson(ContainerElements& elements);
	std::vector<int> buildJacobsthalSequence(int n);


	std::vector<Element> _vec;
	std::deque<Element> _deq;
};

#endif