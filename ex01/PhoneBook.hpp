/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:30:24 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/26 14:46:49 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook {

private:
	Contact			contacts[8];
	std::string		first_name;
	std::string		last_name;
	std::string		phone_number;

public:
	PhoneBook();    //constructor
	~PhoneBook(){};   //destructor
	
	void		add_contact();
	void		remove_contact();
	void		search_contact();
	void		display_contact();
	
	void		exit(); //may not be nessecary
};



#endif