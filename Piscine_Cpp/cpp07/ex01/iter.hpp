/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:23:49 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/08 12:59:59 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T, typename F>
void	iter (T *array, size_t const lenght, F function){
	for(size_t i = 0; i < lenght; i++)
		function(array[i]);
}

#endif