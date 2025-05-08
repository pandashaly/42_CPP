/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:26:31 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 15:19:17 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogCat.hpp"

//OCF
Dog::Dog(void)
{
	this->_type = "Dog🐶";
	this->_brain = new Brain();
	std::cout << "Dog created!" << std::endl;
}

Dog::Dog(const Dog & other) : AAnimal(other)
{
	this->_brain = new Brain(*other.getBrain());
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
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other.getBrain()); //deep copy contents
	}
	std::cout << "Dog assigned 🐶" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof 🐾" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}

//=========================== CAT ===================================

//OCF
Cat::Cat(void)
{
	this->_type = "Cat🐱";
	this->_brain = new Brain();
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat & other) : AAnimal(other)
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
