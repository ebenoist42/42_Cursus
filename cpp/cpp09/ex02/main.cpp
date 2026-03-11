/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:54:52 by ebenoist          #+#    #+#             */
/*   Updated: 2026/02/03 17:23:01 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av){
	if (ac == 1){
		std::cout << "Error : please put numbers\n";
		return 1;
	}
	try{
		PmergeMe Merge;
		Merge.ParseDisplay(ac, av);
		Merge.sortVector();
		Merge.sortDeqeu();
		Merge.CheckDisplay();
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}