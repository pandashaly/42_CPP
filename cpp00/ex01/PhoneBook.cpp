/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:43:56 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/02 02:14:55 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>

PhoneBook::PhoneBook(void) : _size(0), _old(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addNew(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
		this->_contacts[this->_size].save(fn, ln, nn, pn, ds);
		this->_size++;
}

void	PhoneBook::overwriteOld(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
		this->_contacts[this->_old].save(fn, ln, nn, pn, ds);
		this->_old = (this->_old + 1) % 8;
}

void	PhoneBook::createCT(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	if (this->_size < 8)
		addNew(fn, ln, nn, pn, ds);
	else
		overwriteOld(fn, ln, nn, pn, ds);
}

int	PhoneBook::get_size(void)
{
	return (this->_size);
}

void	PhoneBook::print_sum(int i)
{
	this->_contacts[i].print_short(i);
}

void	PhoneBook::print_deets(int i)
{
	this->_contacts[i].print_long(i);
}