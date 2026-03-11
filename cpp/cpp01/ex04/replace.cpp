/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:58:52 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/28 10:51:44 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	ft_filename(char **av)
{
	std::string s1 = av[2];
	std::string s2 = av[3];
	std:: string filename = av[1];
	std::ifstream ifs(filename.c_str());
	if(!ifs.is_open())
	{
		std::cerr << " Error Opening  file" << std::endl;
		return(1);
	}
	std::string line;
	std::ofstream ifs_rename((filename + "_rename").c_str());
	if(!ifs_rename.is_open())
	{
		std::cerr << " Error Opening new file" << std::endl;
		return(1);
	}
	while (std::getline(ifs, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ifs_rename << line << std::endl;
	}
	ifs.close();
	ifs_rename.close();
	return(0);
}
