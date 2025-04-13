/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:29:40 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 19:50:08 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//OCF
Animal::Animal(void) : _type("Panda🐼") 
{
	std::cout << "Animal created!" << std::endl;
}

Animal::Animal(const Animal & other) 
{
	std::cout << "Animal copied!" << std::endl;
	*this = other;
}

Animal::~Animal(void) 
{
	std::cout << "Animal destroyed!" << std::endl;
}

Animal & Animal::operator = (const Animal & other)
{
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

//-------------------
void Animal::makeSound() const
{
	std::cout << "* Unidentifiable animal noise *" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}
