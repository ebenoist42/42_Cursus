/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:56:27 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/08 13:04:23 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void ft_print(const T& elem) {
	std::cout << elem << " ";
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intLength, ft_print<int>);
	std::cout << std::endl;
	return 0;
}
