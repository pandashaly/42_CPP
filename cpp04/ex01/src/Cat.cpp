/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:37:12 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 21:05:27 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//OCF
Cat::Cat(void)
{
	this->_type = "Dog🐶";
	this->_brain = new Brain();
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat & other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	std::cout << "Cat copied!" << std::endl;
}

Cat::~Cat(void) 
{
	delete this->_brain;
	std::cout << "Cat destroyed!" << std::endl;
}

Cat & Cat::operator = (const Cat & other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*this->_brain = *other._brain; //deep copy contents
	}
	std::cout << "Cat assigned 🐶" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Woof woof 🐾" << std::endl;
}
