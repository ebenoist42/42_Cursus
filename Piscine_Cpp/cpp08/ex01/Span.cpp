/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:21:49 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/13 14:15:57 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span (unsigned int N): N_max(N){}

Span::Span (const Span &other) : N_max(other.N_max), N_array(other.N_array) {}

Span& Span::operator=(const Span &other){
	if (this != &other){
		N_max = other.N_max;
		N_array = other.N_array;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int N){
	if (N_array.size() >= N_max)
		throw std::runtime_error("Sorry you can't add more number\n");
	N_array.push_back(N);
}

int Span::shortestSpan()const{
	if (N_array.size() < 2)
		throw std::exception();
	std::vector<int> copie = N_array;
	std::sort(copie.begin(), copie.end());
	int shortest = copie[1] - copie[0];
	for (size_t i = 1; i < copie.size(); i++)
	{
		int diff = copie[i] - copie[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan()const{
	if (N_array.size() < 2)
		throw std::exception();
	int min = *std::min_element(N_array.begin(), N_array.end());
	int max = *std::max_element(N_array.begin(), N_array.end());
	return max - min;
}