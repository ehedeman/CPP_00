/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlon <marlon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:12:41 by ehedeman          #+#    #+#             */
/*   Updated: 2024/09/03 14:49:08 by marlon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//apparently we have two cuz one is for call without input
Account::Account( void ){}

//constructor with input
Account::Account( int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created";
	std::cout << std::endl;
}
//destructor->needs to print all ending values as well as state closed
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

//private functions
void	Account::_displayTimestamp( void )
{
	time_t t_now;

	t_now = std::time(NULL);
	struct tm time = *std::localtime(&t_now);
	
	std::cout << "[";
	std::cout << time.tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << time.tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << time.tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << time.tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << time.tm_min;
	std::cout << std::setfill('0') << std::setw(2) << time.tm_sec;
	std::cout << "] ";
}

//public functions
int		Account::getNbAccounts( void ){return (_nbAccounts);}
int		Account::getTotalAmount( void ){return (_totalAmount);}
int		Account::getNbDeposits( void ){return (_totalNbDeposits);}
int		Account::getNbWithdrawals( void ){return (_totalNbWithdrawals);}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount + deposit << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits + 1;
	std::cout << std::endl;
	//display previous amount and amount etc as well in here, same with withdrawals
	this->_amount += deposit;
	this->_nbDeposits += 1;
	this->_totalAmount += deposit;
	this->_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	std::cout << "amount:" << this->_amount - withdrawal << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals + 1;
	std::cout << std::endl;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals += 1;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}