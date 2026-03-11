/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:38:06 by ebenoist          #+#    #+#             */
/*   Updated: 2026/01/28 17:27:32 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &string) : av(string){}
RPN::RPN(const RPN &other) :Array(other.Array), av(other.av){}
RPN& RPN::operator=(const RPN &other){
	if (this != &other)
		av = other.av;
	return *this;}
RPN::~RPN(){}

static bool IsOperator(char c){
	if(c == '*' || c == '-' || c == '+' || c == '/')
		return true;
	return false;
}

void RPN::Operation(int c){
	int a = Array.top();
	Array.pop();
	int b = Array.top();
	Array.pop();
	long long result;
	if (c == '-')
		result = (long long)b - (long long)a;
	if (c == '*')
		result = (long long)b * (long long)a;
	if (c == '+')
		result = (long long)b + (long long)a;
	if (c == '/'){
		if (a == 0)
			throw std::invalid_argument("Error : can't divise by 0\n");
		else
			result = (long long)b / (long long)a;}
	if (result > INT_MAX || result < INT_MIN)
		throw std::overflow_error("Error: int overflow");
	Array.push(static_cast<int>(result));
}

void RPN::ParseAndFill(){
	size_t ssize = av.size();
	int size = static_cast<int>(ssize);
	for (int i = 0; i < size; i++){
		if(isspace(av[i]))
			continue;
		else if (IsOperator(av[i] ))
			if (Array.size() < 2)
				throw std::invalid_argument("Error: Operator is not in a good place");
			else
				Operation(av[i]);
		else if(!isdigit(av[i]) && !IsOperator(av[i]) && !isspace(av[i]))
			throw std::invalid_argument("Error: Put only number or operator");
		else {
			Array.push(av[i] - '0');
		}
	}
	if (Array.size() != 1)
		throw std::invalid_argument("Error : bad user input");
	std::cout << Array.top()<< std::endl;
}

