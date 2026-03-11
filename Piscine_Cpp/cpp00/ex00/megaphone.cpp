/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:32:55 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/23 12:33:30 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int ac, char **av)
{
	if(ac == 1)
		std::cout <<"* LOUD AND UNBEARABLE FEEDBAK NOISE *";
	else
		for(int i = 1; i < ac; i++)
		{
			for(int j = 0; av[i][j]; j++)
				std::cout << static_cast<char>(toupper(av[i][j]));
		}
	std::cout << std::endl; 
	return 0;
}
