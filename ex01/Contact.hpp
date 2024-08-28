/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:30:19 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/27 13:48:40 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {

private:
	std::string			first_name;
	std::string			nick_name;
	std::string			last_name;
	std::string			phone_number;

public:
	Contact(){};    //constructor
	~Contact(){};   //destructor

	//get-functions
	std::string		get_first_name();
	std::string		get_nick_name();
	std::string		get_last_name();
	std::string		get_phone_number();

	//set-functions
	void			set_first_name(std::string firstname);
	void			set_nick_name(std::string nickname);
	void			set_last_name(std::string lastname);
	void			set_phone_number(std::string phonenumber);
};



#endif