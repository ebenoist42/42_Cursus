/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:45:30 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 10:37:11 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP
#define _ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	
public:
	
	Zombie (std::string name);
	~Zombie ();
	void announce(void);
	
private:

	std::string name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif