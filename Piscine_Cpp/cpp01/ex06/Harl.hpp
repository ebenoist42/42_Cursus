/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:36:45 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/28 14:04:59 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

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

enum Level {DEBUG, INFO, WARNING, ERROR, UNKNOWN};
Level getLevel(std::string levelStr);

#endif