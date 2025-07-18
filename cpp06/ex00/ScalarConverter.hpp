/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:13:52 by ssottori          #+#    #+#             */
/*   Updated: 2025/06/18 01:51:28 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <iomanip>

enum    e_type
{
	SPECIAL = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class ScalarConverter
{
	private:
		ScalarConverter(); //not instantiable
		ScalarConverter(ScalarConverter const &other); //no copy
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string& input);

		static bool isInt(const std::string& str);
		static bool isChar(const std::string& str);
		static bool isFloat(const std::string& str);
		static bool isDouble(const std::string& str);
		static void printResult(char c, long i, float f, double d);
		static void printMore(const std::string& str);

		static bool	isSpecial(const std::string& str);
		static bool parseInput(const std::string& input, e_type type, char& c, int& i, float& f, double& d);

};

e_type	isType(const std::string& str);

// float f = 42; // int to float
// char c = static_cast<char>(97); // int to char

//Except for char parameters, only the decimal notation will be used.
