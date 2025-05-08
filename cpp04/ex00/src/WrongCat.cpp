/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:06:43 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 13:46:18 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//OCF
WrongCat::WrongCat(void)
{
	_type = "Wrong Cat🐱";
	std::cout << "WrongCat created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other)
{
	*this = other;
}

WrongCat::~WrongCat(void) 
{
	std::cout << "WrongCat destroyed!" << std::endl;
}

WrongCat & WrongCat::operator = (const WrongCat & other)
{
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow 🐾" << std::endl;
}
