/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:37:12 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 14:05:24 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//OCF
Cat::Cat(void)
{
    _type = "Cat🐱";
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat & other) : Animal(other)
{
	std::cout << "Cat copied!" << std::endl;
	*this = other;
}

Cat::~Cat(void) 
{
	std::cout << "Cat destroyed!" << std::endl;
}

Cat & Cat::operator = (const Cat & other)
{
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow 🐾" << std::endl;
}
