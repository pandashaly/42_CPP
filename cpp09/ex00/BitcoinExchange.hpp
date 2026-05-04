/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:12:29 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 13:50:44 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;

	public:
		//
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// int getValue();
		// int getData();
		float getRate(const std::string &date);
		void loadDB(const std::string &filename);
		void parsePush(const std::string &line);
		bool isValidDate(const std::string &date);
		bool isValidValue(const std::string &valueStr, float &value);
		void processInput(const std::string &filename);
		std::string trim(const std::string &str);
};

