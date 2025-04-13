/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:06:39 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 14:20:37 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//OCF
WrongAnimal::WrongAnimal(void) : _type("Panda🐼") 
{
	std::cout << "WrongAnimal created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & other) 
{
	std::cout << "WrongAnimal copied!" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "WrongAnimal destroyed!" << std::endl;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal & other)
{
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

//-------------------

void WrongAnimal::makeSound() const
{
	std::cout << "Guten Tag!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}