/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:30:16 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/07 16:14:05 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}
Fixed::Fixed(const int n) // store int
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fractionalBits; //or n * 256
	//eg 10 *256 =2560 in _rawBits -> toFloat will divide 256 and back to 10.0
}

Fixed::Fixed(const float f) // store float
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * 256); //or (f * (1 << -fractionalBits))
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called." << std::endl;
	_rawBits = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}

int Fixed::toInt(void)const
{
	return _rawBits / 256; //or >>_fractionalBits
}

float Fixed::toFloat(void)const
{
	return(float)_rawBits / 256; //or (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void    Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

std::ostream &operator<<(std::ostream &out, const Fixed &val)
{
	return (out << val.toFloat());
}