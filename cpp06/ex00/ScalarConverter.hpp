/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:13:52 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/13 13:34:06 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>


class ScalarConverter
{
	private:
		ScalarConverter(); //not instantiable
		ScalarConverter(ScalarConverter const &other); //no copy
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string& input);

		bool isInt(const std::string& str);
		bool isChar(const std::string& str);
		bool isFloat(const std::string& str);
		bool isDouble(const std::string& str);
		void printResult(char c, long i, float f, double d);
		void printMore(const std::string& str);
};