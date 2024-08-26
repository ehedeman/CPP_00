/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:30:26 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/26 14:24:35 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//for this contact specific function that returns this specific contact's name
std::string		Contact::get_first_name()
{
	return (this->first_name);
}

std::string		Contact::get_last_name()
{
	return (this->last_name);
}

std::string		Contact::get_phone_number()
{
	return (this->phone_number);
}

void	Contact::set_first_name(std::string firstname)
{
	this->first_name = firstname;	
}

void	Contact::set_last_name(std::string lastname)
{
	this->last_name = lastname;
}

void	Contact::set_phone_number(std::string phonenumber)
{
	this->phone_number = phonenumber;
}