/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:58:48 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/07 02:24:11 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//This is the default constructor. sets the required values when it is called & creates object
Fixed::Fixed(void)
{
    std::cout << "Constructor called." << std::endl;
}

//Copy constructors are used to create a new element with the same values as the one passed as param
Fixed::Fixed()
{
    std::cout << "Copy constructor called." << std::endl;
}

//an operator overload lets us define what happens (in this case) when
//we write Fixed a = Fixed b for example
//this could be done for += or -= or any other operator
Fixed::Fixed()
{
    std:;cout << "Copu assignment operator called" << std::endl;
}

/// Default constructor called when we don't the element anymore - clears mem and resources
Fixed::~Fixed(void)
{
    std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return (this->_fixedpt);

}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called." << std::endl;
    return ;
}