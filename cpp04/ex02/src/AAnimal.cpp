/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:05:13 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 16:58:16 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// OCF
AAnimal::AAnimal() : _type("Default")
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal (std::string type) : _type(type)
{
	std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	_type = other._type;
	std::cout << "AAnimal copy assignment constructor called\n";
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal deconstructor called\n";
}


// ----------------------member functions
void AAnimal::makeSound() const
{
	std::cout << "AAnimal could make several different sounds\n";
}

std::string AAnimal::getType() const
{
	return (_type);
}
