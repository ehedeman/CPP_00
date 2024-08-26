/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:43:59 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/26 14:55:36 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	process_input(std::string buff)
{
	std::string	reply;

	if (buff == "EXIT")
	{
		while (1)
		{
			std::cout << "You sure? (yes/no)" << std::endl;
        	std::getline(std::cin, reply);
			if (reply == "yes")
				return (1);
			if (reply == "no")
				break ;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::string	buff;

	if (argc != 1)
	{
		std::cout << "What're you trying to do, huh??" << std::endl;
		return (0);
	}
	else
	{
		while (1)
		{
			std::cout << "How can we help?" << std::endl;
			std::getline(std::cin, buff);
			if (process_input(buff))
				return  (0);
		}
	}
	return (0);
}