/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:43:59 by ehedeman          #+#    #+#             */
/*   Updated: 2024/09/09 13:39:25 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	process_input(std::string buff, PhoneBook *ph)
{
	if (buff == "EXIT")
	{
		if (ph->exit())
			return (1);
	}
	if (buff == "ADD")
		ph->add();
	if (buff == "SEARCH")
	{
		if (ph->display_all())
			return (0);
		ph->search();
	}
	// if (buff == "DISPLAY")
	// 	ph->display();
	// if (buff == "REMOVE")
	// 	ph->remove();
	// if (buff == "HELP")
	// 	ph->help();
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cout << "What're you trying to do, huh??" << std::endl;
		return (0);
	}
	std::string	buff;
	PhoneBook	ph;
	(void)argv;
	while (!std::cin.eof())
	{
		std::cout << "How can we help?" << std::endl;
		std::getline(std::cin, buff);
		if (process_input(buff, &ph))
			return  (0);
	}
	return (0);
}