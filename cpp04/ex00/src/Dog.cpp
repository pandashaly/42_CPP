/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:37:19 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 13:36:39 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//OCF
Dog::Dog(void)
{
    _type = "Dog🐶";
	std::cout << "Dog created!" << std::endl;
}

Dog::Dog(const Dog & other) : Animal(other)
{
	*this = other;
}

Dog::~Dog(void) 
{
	std::cout << "Dog destroyed!" << std::endl;
}

Dog & Dog::operator = (const Dog & other)
{
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof 🐾" << std::endl;
}
