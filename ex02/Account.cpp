/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlon <marlon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:12:41 by ehedeman          #+#    #+#             */
/*   Updated: 2024/09/02 22:25:12 by marlon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

//apparently we have two cuz one is for call without input
Account::Account( void ){}

//constructor with input
Account::Account( int initial_deposit)
{

}
//destructor->needs to print all ending values as well as state closed
Account::~Account( void )
{

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
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	//display previous amount and amount etc as well in here, same with withdrawals
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
}

int		Account::checkAmount( void ) const
{

}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}