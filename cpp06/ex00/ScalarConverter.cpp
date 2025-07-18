/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:30:04 by ssottori          #+#    #+#             */
/*   Updated: 2025/07/18 19:33:27 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string& str) { return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]); }

static double parseValue(const std::string& input)
{
	if (isCharLiteral(input))
		return static_cast<double>(input[0]);

	std::istringstream iss;
	std::string cleaned = input;

	// remove 'f' suffix if it's a float literal
	if (cleaned.length() > 1 && cleaned[cleaned.length() - 1] == 'f'
		&& cleaned != "nanf" && cleaned != "+inff" && cleaned != "-inff")
		cleaned = cleaned.substr(0, cleaned.length() - 1);

	iss.str(cleaned);
	double result;
	iss >> result;

	if (iss.fail() || !iss.eof())
		throw std::runtime_error("Invalid literal");

	return result;
}

static void printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << value << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	double val;

	try {
		val = parseValue(input);
	} catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(val);
	printInt(val);
	printFloat(val);
	printDouble(val);
}
