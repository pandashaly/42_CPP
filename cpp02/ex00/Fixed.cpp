/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:58:48 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/07 13:21:37 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;
//This is the default constructor. sets the required values when it is called & creates object
Fixed::Fixed()
{
	std::cout << "Default Constructor called." << std::endl;
	_rawBits = 0;
}

//baso just copypaste
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called." << std::endl;
	_rawBits = copy.getRawBits();
}

//an operator overload lets us define what happens (in this case) when
//we write Fixed a = Fixed b for example
//this could be done for += or -= or any other operator
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copu assignment operator called" << std::endl;
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return *this;
}

/// Default constructor called when we don't the element anymore - clears mem and resources
Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_rawBits);

}

void    Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_rawBits = raw;
	return ;
}