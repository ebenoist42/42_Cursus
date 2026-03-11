/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:09:37 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/05 15:04:40 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){
	*this = other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	(void) other;
	return *this;
}
ScalarConverter::~ScalarConverter(){}

static bool	is_int(std::string& param)
{
	if (param.empty())
		return false;
	size_t i = 0;
	bool isint = false;
	if (param[i] == '-' || param[i]  == '+')
			i++;
	for (; i < param.length(); i++)
	{
		if(std::isdigit(param[i]))
			isint = true;
		else
			return false;
	}
	return isint;
}

static bool	is_float(std::string& param)
{
	if (param == "nanf" || param == "+inff" || param == "-inff")
		return true;
	size_t i = 0;
	int point = 0;
	if (param[0] == '.' || param.size() < 2 || param[param.size() - 1] != 'f' )
		return false;
	if (param[i] == '-' || param[i] == '+')
		i++;
	for (; i < param.size() - 1; i++)
	{
		if (param[i] == '.'){
			point ++;
			if (point > 1)
				return false;
		}
		else if(!std::isdigit(param[i]))
			return false;
	}
	return true;
}

static bool is_double(std::string& param)
{
	if (param == "nan" || param == "+inf" || param == "-inf")
		return true;
	size_t i = 0;
	int point = 0;
	if (param[i] == '-' || param[i] == '+')
		i++;
	if (param.empty() || param[param.size() - 1] == 'f' )
		return false;
	for (; i < param.size(); i++)
	{
		if (param[i] == '.')
		{
			point++;
			if(point > 1)
				return false;
		}
		else if (!std::isdigit(param[i]))
			return false;
	}
	return true;
}

static bool is_char(std::string& param)
{
	if (param.empty() || param.length() != 1)
		return false;
	if (std::isprint(param[0]) && !std::isdigit(param[0]))
		return true;
	return false;
}

static void	ft_print(int i ,double d ,float f ,char c)
{
	std::string fpoint = "";
	std::string dpoint = "";
	if (c == -1)
		std::cout << "char: Impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: Out of range " << std::endl;
	else if (std::isnan(d) || std::isnan(f))
		std::cout << "int : Impossible " << std::endl;
	else
		std::cout << "int : " << i << std::endl;
	if (f > 1.175494e-38 && f < 3.402823e+38 && std::fmod(f, 1.0f) == 0.0f) // check si f est valide (pas inf etc..) et si cest un entier
		fpoint = ".0";
	if (d > 1.7976931348623157e-308 && d < 1.7976931348623157e+308 && std::fmod(d, 1.0) == 0.0)
		dpoint = ".0";
	std::cout << "float: " << f << fpoint << "f" << std::endl;
	std::cout << "double: " << d << dpoint << std::endl;
	errno = 0;

}

static void	print_int(std::string& param)
{
	int i = 0;
	char c = 0;
	float f;
	double d;
	long l = std::strtol(param.c_str(), NULL, 10);
	if (errno == ERANGE || l < INT_MIN || l > INT_MAX) // erange = erreur de depassement de plage et erno est une variable globale () = 0 quand tout vas bien  
	{
		d = std::strtod(param.c_str(), NULL);
		f = static_cast<float> (d);
		c = -1;
	}
	else{
		i = l;
		d = static_cast<double>(i);
		f = static_cast<float>(i);
	}
	if (c == -1 || d < 128 || d >= 0)
		c = static_cast<char>(d);
	ft_print(i, d, f, c);
	
}

static void	print_char(std::string& param)
{
	char c = param[0];
	int i = static_cast<int>(c);
	double d = static_cast<int>(c);
	float f = static_cast<int>(c);
	ft_print(i, d, f, c);
}

static void	print_float(std::string& param)
{
	int i;
	char c = -1;
	double d;
	float f;
	float tmp = std::strtof(param.c_str(), NULL);
	if (errno == ERANGE){
		d = strtod(param.c_str(), NULL);
		f = static_cast<float> (d);
		i = static_cast<int> (d);
	}
	else{
		f = tmp;
		d = static_cast<double> (f);
		i = static_cast<int> (f);
	}
	if (d >= 0 && d < 128)
		c = static_cast<char>(d);
	ft_print(i, d, f, c);
}

static void	print_double(std::string& param)
{
	double d = std::strtod(param.c_str(), NULL);
	int i = static_cast<int> (d);
	char c = -1;
	float f = static_cast<float> (d);
	if(d >= 0 && d < 128)
		c = static_cast<char> (d);
	ft_print(i, d, f, c);
}

static void	no_printable()
{
	std::cout << "char : Impossible" << std::endl;
	std::cout << "int : Impossible" << std::endl;
	std::cout << "float : Impossible" << std::endl;
	std::cout << "double : Impossible" << std::endl;
}

void ScalarConverter::convert(std::string& param)
{
	if(is_int(param))
		print_int(param);
	else if(is_float(param))
		print_float(param);
	else if(is_double(param))
		print_double(param);
	else if(is_char(param))
		print_char(param);
	else
		no_printable();
}