/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:06:43 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 14:34:58 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//OCF
WrongCat::WrongCat(void)
{
	_type = "Cat🐱";
	std::cout << "WrongCat created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other)
{
	std::cout << "WrongCat copied!" << std::endl;
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
	std::cout << "Meow Meow 🐾" << std::endl;
}
