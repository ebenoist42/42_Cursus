/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:45:56 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/26 11:16:25 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP
#define _ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{

private :
			std::string name;
public :
			Zombie();
			~Zombie();
			void announce(void);
			void set_name_zombie(std::string name);
};

Zombie* zombieHorde (int N, std::string name);

#endif