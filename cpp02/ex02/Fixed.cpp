/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:30:16 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/12 17:10:38 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Return a new object — arithmetic should be non-destructive.
#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(){
	_rawBits = 0;
}
Fixed::Fixed(const int n) // store int
{
	_rawBits = n << _fractionalBits; //or n * 256
	//eg 10 *256 =2560 in _rawBits -> toFloat will divide 256 and back to 10.0
}

Fixed::Fixed(const float f) // store float
{
	_rawBits = roundf(f * 256); //or (f * (1 << -fractionalBits))
}

Fixed::Fixed(const Fixed &copy)
{
	_rawBits = copy.getRawBits();
}

bool Fixed::operator > (const Fixed & other) const
{
	return (this->_rawBits > other.getRawBits());
}

bool Fixed::operator < (const Fixed & other) const
{
	return (this->_rawBits < other.getRawBits());
}

bool Fixed::operator >= (const Fixed & other) const
{
	return (this->_rawBits >= other.getRawBits());
}

bool Fixed::operator <= (const Fixed & other) const
{
	return (this->_rawBits <= other.getRawBits());
}

bool Fixed::operator == (const Fixed & other) const
{
	return (this->_rawBits == other.getRawBits());
}

bool Fixed::operator != (const Fixed & other) const
{
	return (this->_rawBits != other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != & other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return(Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return(Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return(Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return(Fixed(this->toFloat() / other.toFloat()));
}

//incrememnt -------------------------
Fixed &Fixed::operator++()
{
	this->_rawBits++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_rawBits--;
	return tmp;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_rawBits++;
	return tmp;
}

//min max

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

//functions ---------------------------
Fixed::~Fixed(void) {}

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
//---------------------
std::ostream &operator<<(std::ostream &out, const Fixed &val)
{
	return (out << val.toFloat());
}

