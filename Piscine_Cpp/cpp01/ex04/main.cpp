/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:57:41 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/28 10:51:17 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main (int ac, char **av)
{
	if(ac != 4)
	{
		std::cout << "Please put 3 parameters" << std::endl;
		return(0);
	}
	return(ft_filename(av));
}
