/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:51:50 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/02 02:00:25 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::save(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickName = nn;
	this->_phoneNumber = pn;
	this->_darkestSecret = ds;
};

void	Contact::print_short(int i)
{
	// "|   Index    | First Name | Last Name  |  Nickname  |"
	std::cout << "| " << std::setw(10) << i + 1 << " | ";
	if (this->_firstName.length() > 10)
		std::cout << std::setw(10) << this->_firstName.substr(0, 9) + '.' << " | ";
	else
		std::cout << std::setw(10) << this->_firstName << " | ";
	if (this->_lastName.length() > 10)
		std::cout << std::setw(10) << this->_lastName.substr(0, 9) + '.' << " | ";
	else
		std::cout << std::setw(10) << this->_lastName << " | ";
	if (this->_lastName.length() > 10)
		std::cout << std::setw(10) << this->_nickName.substr(0, 9) + '.' << " | ";
	else
		std::cout << std::setw(10) << this->_nickName << " | ";
	std::cout << std::endl;
}

void	Contact::print_long(int i)
{
	std::cout << "Index: " << i + 1 << std::endl;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}