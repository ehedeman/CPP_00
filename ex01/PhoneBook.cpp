/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlon <marlon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:30:22 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/28 23:05:35 by marlon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	std::cout << "*---------------------------------------------------------------------*" << std::endl;
	std::cout << "|                                                                     |" << std::endl;
	std::cout << "|                     Hi, welcome to my phonebook :D                  |" << std::endl;
	std::cout << "|                                                                     |" << std::endl;
	std::cout << "|                             (I tried lol)                           |" << std::endl;
	std::cout << "|                                                                     |" << std::endl;
	std::cout << "*---------------------------------------------------------------------*" << std::endl;
	std::cout << "For doing stuff: " << std::endl;
	std::cout << std::endl;
	std::cout << "SEARCH: Searches for a contact." << std::endl;
	std::cout << "ADD: Adds a new contact." << std::endl;
	std::cout << "HELP: Displays this list again." << std::endl;
	std::cout << "REMOVE: Removes a contact." << std::endl;
	std::cout << "DISPLAY: Shows your contacts." << std::endl;
	std::cout << "EXIT: Leaves this phonebook, everything will be lost :(" << std::endl;
}

void	PhoneBook::add()
{
	std::string	reply;

	if (this->index > 7)
	{
		if (warn_user_overwrite())
			return ;
	}
	reply = "";
	while (!std::cin.eof() && reply == "")
	{
		std::cout << "Please enter first name" << std::endl;
		std::getline(std::cin, reply);
		this->contacts[this->index % 8].set_first_name(reply); // %8 weil wie willste sonst wissen wenn contact nr. 2 zum
	}
	reply = "";
	while (!std::cin.eof() && reply == "")
	{
		std::cout << "Please enter last name" << std::endl;		// 3. mal ueberschrieben wird? wenn du immer auf 0 setzt
		std::getline(std::cin, reply);
		this->contacts[this->index % 8].set_last_name(reply);
	}
	reply = "";
	while (!std::cin.eof() && reply == "")
	{
		std::cout << "Please enter nick name" << std::endl;		// 3. mal ueberschrieben wird? wenn du immer auf 0 setzt
		std::getline(std::cin, reply);
		this->contacts[this->index % 8].set_nick_name(reply);
	}
	reply = "";
	while (!std::cin.eof() && reply == "")
	{
		std::cout << "Please enter phone number" << std::endl;
		std::getline(std::cin, reply);
		if (check_valid_number(reply))
		{
			reply = "";
			continue ;
		}
		this->contacts[this->index % 8].set_phone_number(reply);
	}
	if (!std::cin.eof())
		std::cout << "Your contact has been saved :D" << std::endl;
	this->index++;
}

void	PhoneBook::search()
{
	std::string		reply;
	int				i = 0;

	while (i < 8)
	{
		if (!this->contacts[i].get_first_name().size())
		{
			break ;
		}
		i++;
	}
	while (!std::cin.eof() && reply == "")
	{
		std::cout << "What Contact are you searching for? (Enter index)" << std::endl;
		std::getline(std::cin, reply);
		if (check_valid_index(reply, i))
		{
			std::cout << "Sorry, thats no valid entry." << std::endl;
			reply = "";
		}
	}
	i = std::atoi(reply.c_str());
	this->display_single(i);
}

int	PhoneBook::exit()
{
	std::string	reply;
	int			i = 0;

	while (!std::cin.eof())
	{
		std::cout << "You sure? (yes/no)" << std::endl;
		std::getline(std::cin, reply);
		if (reply == "yes")
		{
			while (i < 8)
			{
				if (!this->contacts[i].get_first_name().size())
				{
					i++;
					continue ;
				}
				else
				{
					std::cout << "So this is it?? All your precious contacts!! ╭∩╮( •̀_•́ )╭∩╮" << std::endl;
					return (1);
				}
			}
			std::cout << "Fine. You didnt have anything saved anyways •`_´•" << std::endl;
			return (1);
		}
		if (reply == "no")
			break ;
	}
	return (0);
}

void	PhoneBook::display_single(int index)
{
	int i = 0;
	while (i++ < 11)
	{
		std::cout << "-" << std::endl;
		usleep(500);
	}
	std::cout << "First Name: ";
	std::cout << this->contacts[index].get_first_name();
	std::cout << std::endl;
	std::cout << "Lastt Name: ";
	std::cout << this->contacts[index].get_last_name();
	std::cout << std::endl;
	std::cout << "Nick Name: ";
	std::cout << this->contacts[index].get_nick_name();
	std::cout << std::endl;
	std::cout << "Phone Number: ";
	std::cout << this->contacts[index].get_phone_number();
	std::cout << std::endl;
}

int	PhoneBook::display_all()
{
	int		i = 0;
	int		j = 0;
	char 	nbr;

	while (i < 8)
	{
		if (!this->contacts[i].get_first_name().size())
		{
			i++;
			j++;
			continue ;
		}
		i++;
	}
	if (j == 8)
	{
		std::cout << "No Contacts Saved Yet." << std::endl;
		return (1);
	}
	//first row:
	j = 0;
	i = 0;
	while (j++ <= 43)
		std::cout << "-";
	std::cout << std::endl;
	while (i < 8 && this->contacts[i].get_first_name().size())
	{
		nbr = i + 0x30;
		//collumn 1 (index):
		std::cout << nbr << "         |";
		//collumn 2 (first name):
		print_contact_data(this->contacts[i].get_first_name());
		std::cout << "|";
		//collumn 3 (last name):
		print_contact_data(this->contacts[i].get_last_name());
		std::cout << "|";
		//collumn 4 (nick name):
		print_contact_data(this->contacts[i].get_nick_name());
		std::cout << std::endl;
		i++;
	}
	//last row
	j = 0;
	while (j++ <= 43)
		std::cout << "-";
	std::cout << std::endl;
	return (0);
}

//requirements for display:
//
//4 collumns: do one collumn in one row so 4 while loops per thing
//ten characters wide: iterate through i <= 9 (last one needs to be a dot if word too long)
//dot at the end: if theres still word left after loop then place dot
//right-alligned: text starts after seperating character (after that spaces if nesseary)
//




// void	PhoneBook::help()
// {
// 	std::cout << "Already forgot the commands, huh? Alright." << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "SEARCH: Searches for a contact." << std::endl;
// 	std::cout << "ADD: Adds a new contact." << std::endl;
// 	std::cout << "HELP: Displays this list again." << std::endl;
// 	std::cout << "REMOVE: Removes a contact." << std::endl;
// 	std::cout << "DISPLAY: Shows your contacts." << std::endl;
// 	std::cout << "EXIT: Leaves this phonebook, everything will be lost :(" << std::endl;
// }

// void	PhoneBook::remove()
// {
// 	std::string	first_n;
// 	std::string	last_n;
// 	int			i = 0;
// 	int			found = 0;

// 	std::cout << "What contact do you want to remove? (Enter first name)" << std::endl;
// 	std::getline(std::cin, first_n);
// 	while (i < 8)
// 	{
// 		if (this->contacts[i].get_first_name() == first_n)
// 			found++;
// 		i++;
// 	}
// 	if (!found)
// 	{
// 		std::cout << "Sorry, you dont seem to have a contact with that name." << std::endl;
// 		return ;
// 	}
// 	else if (found == 1)
// 	{
// 		i = 0;
// 		while (i < 8)
// 		{
// 			if (this->contacts[i].get_first_name() == first_n)
// 			{
// 				this->contacts[i].set_first_name("");
// 				this->contacts[i].set_last_name("");
// 				this->contacts[i].set_nick_name("");
// 				this->contacts[i].set_phone_number("");
// 				return ;
// 			}
// 			i++;
// 		}
// 	}
// 	else if (found > 1)
// 	{
// 		std::cout << "You seem to have multiple contacts with that name." << std::endl;
// 		std::cout << "Please enter last name to specify: " << std::endl;
// 		std::getline(std::cin, last_n);
// 		i = 0;
// 		while (i < 8)
// 		{
// 			if (this->contacts[i].get_first_name() == first_n)
// 			{
// 				if (this->contacts[i].get_last_name() == last_n)
// 				{
// 					this->contacts[i].set_first_name("");
// 					this->contacts[i].set_last_name("");
// 					this->contacts[i].set_nick_name("");
// 					this->contacts[i].set_phone_number("");
// 					return ;
// 				}
// 			}
// 			i++;
// 		}
// 	}
// 	std::cout << "Sorry, you dont seem to have a contact with that name." << std::endl;
// }

// void	PhoneBook::search()
// {
// 	int			i = 0;
// 	int			found = 0;
// 	char		nbr;
// 	std::string	first_n;
// 	std::string	last_n;

// 	std::cout << "What contact are you looking for? (Enter first name)" << std::endl;
// 	std::getline(std::cin, first_n);
// 	while (i < 8)
// 	{
// 		if (this->contacts[i].get_first_name() == first_n)
// 			found++;
// 		i++;
// 	}
// 	if (!found)
// 	{
// 		std::cout << "Sorry, you dont seem to have a contact with that name." << std::endl;
// 		return ;
// 	}
// 	else if (found == 1)
// 	{
// 		i = 0;
// 		while (i < 8)
// 		{
// 			nbr = i + 1 + 0x30;
// 			if (this->contacts[i].get_first_name() == first_n)
// 			{
// 				std::cout << "Contact [ " << nbr << " ]" << std::endl;
// 				std::cout << "First Name: " << this->contacts[i].get_first_name() << std::endl;
// 				std::cout << "Last Name: " << this->contacts[i].get_last_name() << std::endl;
// 				std::cout << "Nick Name: " << this->contacts[i].get_nick_name() << std::endl;
// 				std::cout << "Phone Number: " << this->contacts[i].get_phone_number() << std::endl << std::endl;
// 				return ;
// 			}
// 		}
// 	}
// 	else if (found > 1)
// 	{
// 		std::cout << "You seem to have multiple contacts with that name." << std::endl;
// 		std::cout << "Please enter last name to specify: " << std::endl;
// 		std::getline(std::cin, last_n);
// 		i = 0;
// 		while (i < 8)
// 		{
// 			nbr = i + 1 + 0x30;
// 			if (this->contacts[i].get_first_name() == first_n)
// 			{
// 				if (this->contacts[i].get_last_name() == last_n)
// 				{
// 					std::cout << "Contact [ " << nbr << " ]" << std::endl;
// 					std::cout << "First Name: " << this->contacts[i].get_first_name() << std::endl;
// 					std::cout << "Last Name: " << this->contacts[i].get_last_name() << std::endl;
// 					std::cout << "Nick Name: " << this->contacts[i].get_nick_name() << std::endl;
// 					std::cout << "Phone Number: " << this->contacts[i].get_phone_number() << std::endl << std::endl;
// 					return ;
// 				}
// 			}
// 			i++;
// 		}
// 	}
// 	std::cout << "Sorry, you dont seem to have a contact with that name." << std::endl;
// }