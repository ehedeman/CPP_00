/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:30:24 by ehedeman          #+#    #+#             */
/*   Updated: 2024/09/09 13:39:07 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "PhoneBook_utils.hpp"
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

class PhoneBook {

private:
	Contact			contacts[8];
	std::string		first_name;
	std::string		last_name;
	std::string		phone_number;
	int				index; //index of what contact were currently looking at

public:
	PhoneBook();    //constructor
	~PhoneBook(){};   //destructor

	void		add();
	void		search();
	int			exit();
	void		help();
	int			display_all();
	void		display_single(int index);
	void		remove();
};



#endif