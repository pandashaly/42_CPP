/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:30:04 by ssottori          #+#    #+#             */
/*   Updated: 2025/07/18 19:11:41 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printMore(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nanf" || str == "+inff" || str == "-inff") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
	} else {
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

void ScalarConverter::printResult(char c, long i, float f, double d)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool ScalarConverter::isChar(const std::string& str)
{
	if (str.length() == 1 && !isdigit(str[0]) && std::isprint(str[0]))
		return true;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && std::isprint(str[1]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& str)
{
	size_t i = 0;
	if (str.empty()) return false;
	if (str[0] == '-' || str[0] == '+') i++;
	if (i == str.length()) return false;
	for (; i < str.length(); ++i)
		if (!isdigit(str[i])) return false;
	return true;
}

bool ScalarConverter::isSpecial(const std::string& str)
{
	return (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "+inff" || str == "-inff");
}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (isSpecial(str)) return true;
	size_t len = str.length();
	if (len < 2 || str[len - 1] != 'f') return false;
	bool dot = false;
	size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	for (; i < len - 1; ++i) {
		if (str[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!isdigit(str[i])) return false;
	}
	return dot;
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (isSpecial(str)) return true;
	size_t len = str.length();
	if (len < 1) return false;
	bool dot = false;
	size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	for (; i < len; ++i) {
		if (str[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!isdigit(str[i])) return false;
	}
	return dot;
}

e_type isType(const std::string& str)
{
	if (ScalarConverter::isSpecial(str)) return SPECIAL;
	if (ScalarConverter::isChar(str)) return CHAR;
	if (ScalarConverter::isInt(str)) return INT;
	if (ScalarConverter::isFloat(str)) return FLOAT;
	if (ScalarConverter::isDouble(str)) return DOUBLE;
	return INVALID;
}

bool ScalarConverter::parseInput(const std::string& input, e_type type, char& c, int& i, float& f, double& d)
{
	try {
		switch (type) {
			case CHAR:
				c = (input.length() == 1) ? input[0] : input[1];
				i = static_cast<int>(c);
				f = static_cast<float>(c);
				d = static_cast<double>(c);
				return true;


			//testing diff ones
			case INT: {
				std::istringstream iss(input);
				long l;
				iss >> l;
				if (iss.fail() || !iss.eof())
					return false;
				if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
					return false;
				i = static_cast<int>(l);
				c = static_cast<char>(i);
				f = static_cast<float>(i);
				d = static_cast<double>(i);
				return true;
			}

			case FLOAT: {
				std::istringstream iss(input);
				iss >> f;
				if (iss.fail() || !iss.eof())
					return false;
				if (std::isinf(f))
					return false;
				c = static_cast<char>(f);
				i = static_cast<int>(f);
				d = static_cast<double>(f);
				return true;
			}

			case DOUBLE: {
				std::istringstream iss(input);
				iss >> d;
				if (iss.fail() || !iss.eof())
					return false;
				if (std::isinf(d))
					return false;
				c = static_cast<char>(d);
				i = static_cast<int>(d);
				f = static_cast<float>(d);
				return true;
			}

			default:
				return false;
		}
	} catch (...) {
		return false;
	}
}

void ScalarConverter::convert(const std::string& input)
{
	e_type type = isType(input);
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	if (type == SPECIAL) {
		printMore(input);
		return;
	}
	if (!parseInput(input, type, c, i, f, d)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printResult(c, i, f, d);
}

