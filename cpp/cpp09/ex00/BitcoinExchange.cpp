/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:58:10 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/21 13:36:10 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include<bits/stdc++.h>
#include <string>

BitcoinExchange::BitcoinExchange (const std::string &filename) : filename(filename){
	std::ifstream csv;
	csv.open("data.csv");
	if(!csv.is_open())
		throw std::runtime_error("Opening data.csv did not work\n");
	std::string line;
	std::getline(csv, line);
	while(std::getline(csv, line))
	{
		std::stringstream stringline(line);
		std::string date;
		std::string stringprice;
		std::getline(stringline, date, ',');
		std::getline(stringline, stringprice);
		double price = std::atof(stringprice.c_str());
		float fprice = static_cast<float>(price);
		data_csv[date] = fprice;
	}
}
BitcoinExchange::BitcoinExchange ( const BitcoinExchange &other):  data_csv(other.data_csv),filename(other.filename){}
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange &other){
	if (this != &other){
		filename = other.filename;
		data_csv = other.data_csv;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

void	BitcoinExchange::open(){
	file.open(filename.c_str());
	if(!file.is_open())
		throw std::runtime_error("Opening filename.txt did not work\n");
}

static bool check_year(std::string year)
{
	int years = std::atof(year.c_str());
	if (years < 2009 || years > 2022)
		return false;
	for (size_t i = 0 ; i < year.size() ; i++)
	{
		if(!std::isdigit(year[i]))
			return false;
	}
	return true;
}

static bool isLeapYear(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

static bool check_month(std::string month, std::string day, std::string year)
{
	int days = std::atof(day.c_str());
	int months = std::atof(month.c_str());
	int years = std::atof(year.c_str());
	if (months < 1 || months > 12)
		return false;
	for (size_t i = 0 ; i < month.size() ; i++)
	{
		if(!std::isdigit(month[i]))
			return false;
	}
	if (months == 2 && days >= 30){

		std::cout << "Sorry, in February there cannot be more than 29 days.\n";
		return false;
	}
	int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (months == 2 && isLeapYear(years))
		daysInMonth[1] = 29;
	if (days < 1 || days > daysInMonth[months - 1])
		return false;
	return true;
}

static bool check_day(std::string day)
{
	int days = std::atof(day.c_str());
	for (size_t i = 0 ; i < day.size() ; i++)
	{
		if(!std::isdigit(day[i]))
			return false;
	}
	if (days < 1 || days > 31)
		return false;
	return true;
}

static bool check_synthaxe(std::string synthaxe)
{
	if (synthaxe != "|")
		return false;
	return true;
}

static bool check_value(std::string value, std::string line)
{
	double dbtc = std::atof(value.c_str());
	float btc = static_cast<float>(dbtc);
	int point = 0;
	size_t i = 0;
	if (value[0] == '-' || value[0] == '+' )
		i++;
	for ( ; i < value.size() ; i++)
	{
		if (value[i] == '.'){
			i++;
			point++;}
		if(!std::isdigit(value[i]) || point > 1 || value[0] == '.'){
			std::cout << "Error: Synthaxe value not respected for -> " << line << std::endl;
			return false;}
	}
	if(btc <= 0){
		std::cout << "Error: not a positive number.\n";
		return false;}
	if (btc > 1000){
		std::cout << "Error: too large a number.\n";
		return false;}
	return true;
}

void BitcoinExchange::print(std::string year, std::string month, std::string day, std::string string){
	double value = atof(string.c_str());
	float fvalue = static_cast<float>(value);
	std::string dates = year + '-' + month + '-' + day;
	for (std::map<std::string, float>::iterator it = data_csv.begin(); it != data_csv.end(); it ++)
	{
		if(it->first == dates){
			std::cout << it->second * fvalue << std::endl;
			return;}
	}
	std::map<std::string, float>::iterator it = data_csv.upper_bound (dates);
	if(it != data_csv.begin()){
		--it;
		std::cout << it->second * fvalue << std::endl;}
	else
		std::cerr << "Error: Date not found in data.csv\n";
}

void	BitcoinExchange::parse(){
	
	bool titre;
	bool years;
	bool months;
	bool days;
	bool synthaxes;
	bool number;
	std::string line;
	std::string year;
	std::string month;
	std::string day;
	std::string synthaxe;
	std::string value;
	std::getline(file, line);
	if (line == "date | value"){
		titre = true;
	}
	while(std::getline(file, line))
	{
		std::stringstream sl(line);
		std::getline(sl, year, '-');
		years = check_year(year);
		std::getline(sl, month, '-');
		std::getline(sl, day, ' ');
		months = check_month(month, day, year);
		days = check_day(day);
		if (!years || !months || !days)
		{
			std::cout << "Error: bad input => " << year << '-' << month << '-' << day << std::endl;
			continue;
		}
		std::string dates = year + '-' + month + '-' + day;
		std::getline(sl, synthaxe, ' ');
		synthaxes = check_synthaxe(synthaxe);
		std::getline(sl, value);
		number = check_value(value, line);
		if (titre && years && months && days && synthaxes && number)
		{	
			std::cout << year << '-' << month << '-' << day << " => " << value << " = ";
			BitcoinExchange::print(year, month, day, value);
		}
	}
}



