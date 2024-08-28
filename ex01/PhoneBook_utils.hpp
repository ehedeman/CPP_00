/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:56:56 by ehedeman          #+#    #+#             */
/*   Updated: 2024/08/27 14:42:53 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int 	check_valid_number(std::string str);
int 	warn_user_overwrite();
int 	check_valid_index(std::string index, int number_contacts);
void	print_contact_data(std::string str);