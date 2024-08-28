/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:12:41 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/28 13:47:33 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
//constructor
Account::Account( int initial_deposit)
{

}
//destructor
Account::~Account( void )
{

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
	
}

bool	Account::makeWithdrawal(int withdrawal)
{
	
}

int		Account::checkAmount( void ) const
{

}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

//private functions
void	Account::_displayTimestamp( void )
{

}

//idk why we have two of this
Account::Account( void )
{

}