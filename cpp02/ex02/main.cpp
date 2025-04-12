/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:27:50 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/12 17:09:51 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const	b( Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl; //same as << a.toFloat() <<
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}

//Fixed a;                     // calls Fixed::Fixed() — sets _rawBits = 0
//std::cout << a << std::endl; // calls operator<<
                             // → calls toFloat()
                             // → returns 0.0
                             // → is printed


// int main() {
// 	Fixed a(5.5f);
// 	Fixed b(2);
// 	Fixed c(8);
// 	Fixed d(5.5f);

// 	//+1 raw unit = 1 / 256 ≈ 0.00391
// 	std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;

// 	// Test arithmetic operators
// 	std::cout << "a + b = " << (a + b) << std::endl;
// 	std::cout << "a - b = " << (a - b) << std::endl;
// 	std::cout << "a * b = " << (a * b) << std::endl;
// 	std::cout << "a / b = " << (a / b) << std::endl;

// 	// Test comparison operators
// 	std::cout << "a > b ? " << (a > b) << std::endl;
// 	std::cout << "a < b ? " << (a < b) << std::endl;
// 	std::cout << "a >= d ? " << (a >= d) << std::endl;
// 	std::cout << "a <= d ? " << (a <= d) << std::endl;
// 	std::cout << "a == d ? " << (a == d) << std::endl;
// 	std::cout << "a != d ? " << (a != d) << std::endl;

// 	// Test increment and decrement
// 	std::cout << "a before ++: " << a << std::endl;
// 	std::cout << "++a: " << ++a << std::endl;
// 	std::cout << "a after ++: " << a << std::endl;
// 	std::cout << "a++: " << a++ << std::endl;
// 	std::cout << "a after a++: " << a << std::endl;

// 	std::cout << "b before --: " << b << std::endl;
// 	std::cout << "--b: " << --b << std::endl;
// 	std::cout << "b after --: " << b << std::endl;
// 	std::cout << "b--: " << b-- << std::endl;
// 	std::cout << "b after b--: " << b << std::endl;

// 	// Test min/max
// 	std::cout << "min(a, c) = " << Fixed::min(a, c) << std::endl;
// 	std::cout << "max(a, c) = " << Fixed::max(a, c) << std::endl;

// 	return 0;
// }