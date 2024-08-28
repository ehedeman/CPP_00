/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:12:41 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/28 13:11:24 by ehedeman         ###   ########.fr       */
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
	int i = 0;

	while (i < getNbAccounts())
	{
		Account::_displayTimestamp();
		std::cout << "index:" << std::to_string(i);
		std::cout << ";amount:" << std::to_string(Account::getTotalAmount());
		std::cout << ";deposits:" << std::to_string(Account::getNbDeposits());
		std::cout << ";withdrawals:" << std::to_string(Account::getNbWithdrawals());
		std::cout << std::endl;
		i++;
	}
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

}

//private functions
void	Account::_displayTimestamp( void )
{

}

//idk why we have two of this
Account::Account( void )
{

}