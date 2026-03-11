/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:58:07 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/21 11:11:10 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <string>
#include <iostream>
#include <limits>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>

class BitcoinExchange {
	private :
		std::map <std::string , float> data_csv;
		std::string filename;
		std::ifstream file;

	public :
		BitcoinExchange (const std::string &filename);
		BitcoinExchange ( const BitcoinExchange &other);
		BitcoinExchange& operator= (const BitcoinExchange &other);
		~BitcoinExchange();
		void	parse();
		void	open();
		void	print(std::string year, std::string month, std::string day, std::string string);
};

#endif