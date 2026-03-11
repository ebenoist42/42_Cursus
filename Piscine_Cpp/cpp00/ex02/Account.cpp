/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:22:20 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/24 11:39:55 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account:: _nbAccounts = 0;
int Account:: _totalAmount = 0;
int Account:: _totalNbDeposits = 0;
int Account:: _totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);
	
	char buffer[20];
	std::strftime(buffer, size_t(buffer), "[%Y%m%d_%H%M%S]", ltm);
	std::cout << buffer;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	_totalNbDeposits -= _nbDeposits;
	_nbAccounts --;
	_totalAmount -= checkAmount();
	_totalNbWithdrawals -= _nbWithdrawals;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amoun:" << checkAmount() << ";deposit:" << deposit;
	_amount = checkAmount() + deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << ";amount:" << checkAmount() << ";nb_deposits:" << _nbDeposits << std::endl;
}

int	Account::checkAmount( void ) const
{
	return _amount;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount;" << checkAmount() << ";withdrawal:";
	if(withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return(false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return(true);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}