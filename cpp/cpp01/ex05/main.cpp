/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:00:35 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/28 13:42:58 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ()
{
	Harl A;
	A.complain("DEBUG");
	A.complain("INFO");
	A.complain("WARNING");
	A.complain("ERROR");
}