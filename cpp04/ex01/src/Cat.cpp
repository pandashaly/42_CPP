/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:37:12 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 16:57:52 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//OCF
Cat::Cat(void)
{
	this->_type = "Cat🐱";
	this->_brain = new Brain();
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat & other) : Animal(other)
{
	this->_brain = new Brain(*other.getBrain()); //deep copy
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
		this->_brain = new Brain(*other.getBrain()); //deep copy contents
	}
	std::cout << "Cat assigned 😸" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow 🐾" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}
