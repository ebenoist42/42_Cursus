/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:57:15 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/07 17:17:56 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	
	public:
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap (const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys(void);	
	private:

};

#endif
