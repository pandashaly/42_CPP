/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:30:04 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 23:24:58 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
    { (void)other; return *this; }

ScalarConverter::~ScalarConverter() {}

// This is where the main logic will go
void ScalarConverter::convert(const std::string& input) {
	std::cout << "Received input: " << input << std::endl;
	// We’ll figure out the type and convert it here
}

