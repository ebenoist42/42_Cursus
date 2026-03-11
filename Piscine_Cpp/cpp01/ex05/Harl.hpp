/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:00:47 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/28 13:27:48 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
#define HARL_CPP

#include <fstream>
#include <iostream>
#include <string>


class Harl{

	private:
		void debug(void);
		void info (void);
		void warning(void);
		void error (void);

	public:
		void complain(std::string level);
		Harl();
		~Harl();
};

#endif