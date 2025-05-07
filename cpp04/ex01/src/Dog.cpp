/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:37:19 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 00:31:37 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//OCF
Dog::Dog(void)
{
	this->_type = "Dog🐶";
	this->_brain = new Brain();
	std::cout << "Dog created!" << std::endl;
}

Dog::Dog(const Dog & other) : Animal(other)
{
	this->_brain = new Brain(other.gainBrain());
	this->_type = other._type;
	std::cout << "Dog copied!" << std::endl;
}

Dog::~Dog(void) 
{
	delete this->_brain;
	std::cout << "Dog destroyed!" << std::endl;
}

Dog & Dog::operator = (const Dog & other)
{
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = new Brain(other.gainBrain()); //deep copy contents
	}
	std::cout << "Dog assigned 🐶" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof 🐾" << std::endl;
}

Brain& Dog::gainBrain() const
{
	return (*(this->_brain));
}