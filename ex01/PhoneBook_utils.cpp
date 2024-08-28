/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:57:15 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/28 10:04:26 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	check_valid_number(std::string str)
{
	int	i = 0;

	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
		{
			std::cout << "Invalid: none digit-character detected." << std::endl;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_valid_index(std::string index, int number_contacts)
{
	int i = 0;
	while (index[i])
		i++;
	if (i > 1)
		return (1);
	else if (!i)
		return (0);
	else
	{
		if (isdigit(index[0]))
		{
			if (atoi(index.c_str()) < number_contacts && atoi(index.c_str()) >= 0)
				return (0);
		}
	}
	return (1);
}

int	warn_user_overwrite()
{
	std::string reply;

	while (!std::cin.eof())
	{
		std::cout << "Warning: the max. number of contacts has been saved." << std::endl;
		std::cout << "Proceed? (yes/no)" << std::endl;
		std::getline(std::cin, reply);
		if (reply == "yes")
			break ;
		if (reply == "no")
			return (1) ;
	}
	return (0);
}

void	print_contact_data(std::string str)
{
	int	i = 0;

	while (i <= 9 && str[i])
	{
		if (i == 9 && str[i + 1])
			break ;
		std::cout << str[i];
		i++;
	}
	if (str[i])
	{
		std::cout << ".";
		i++;
	}
	if (i < 9)
	{
		while (i < 9)
		{
			std::cout << " ";
			i++;
		}
	}
}