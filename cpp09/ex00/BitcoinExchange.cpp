/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:12:07 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 14:41:24 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#define RED "\033[31m"
#define RESET "\033[0m"

// OCF as requred by subject
//std::map handles its own memory
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

//----------

//input = "date | value" (with spaces)
//removing trailing spaces
std::string BitcoinExchange::trim(const std::string &str)
{
	size_t start;
	size_t end;

	start = str.find_first_not_of(" \t");
	end = str.find_last_not_of(" \t");
	// brooooooo why r spaces breaking everythinggggg
	if (start == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
	// std::cout << "[" << str << "]" << std::endl; // debug: checking hidden spaces
}
//took me longer than expected to realize spaces were breaking everything :)

//loads bitcoin price history into map
void BitcoinExchange::loadDB(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
	{
		std::cerr << RED << "Error: could not open database. :(" << RESET << std::endl;
		return;
	}
	std::getline(file, line); //skip header line ("date,exchange_rate")
	while (std::getline(file, line))
		parsePush(line);
	file.close();
}

void BitcoinExchange::parsePush(const std::string &line)
{
	size_t comma;
	std::string date;
	std::string rateStr;
	std::istringstream iss("");
	float rate;
	// std::cout << "LINE: " << line << std::endl; // debug

	comma = line.find(',');
	if (comma == std::string::npos)
		return; // ?????why is this even a thing
	date = trim(line.substr(0, comma));
	rateStr = trim(line.substr(comma + 1));
	if (!isValidDate(date)) //(probably unnecessary but safeer ig)
		return;
	iss.clear();
	iss.str(rateStr);
	iss >> rate;
	if (iss.fail() || !iss.eof())
		return;
	_db[date] = rate;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	int year;
	int month;
	int day;
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leap;
	int i;

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	i = 0;
	while (i < 10)
	{
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return false;
		i++;
	}

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	leap = false; //leap year checks just in case
	//probably overkill but whatever
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		leap = true;
	if (leap)
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
	std::istringstream iss(valueStr);

	if (valueStr.empty())
	{
		std::cerr << RED << "Error: bad input => " << RESET << valueStr << std::endl;
		return false;
	}
	iss >> value;
	if (iss.fail() || !iss.eof())
	{
		std::cerr << RED << "Error: bad input => " << RESET << valueStr << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << RED << "Error: too large a number." << RESET << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::getRate(const std::string &date)
{
	std::map<std::string, float>::iterator it;

	it = _db.lower_bound(date);
	if (it != _db.end() && it->first == date)
		return it->second;
	if (it == _db.begin())
		return -1;
	--it; 	// lower_bound found a bigger date, so go one step back
	return it->second;
}

// reads input file and calculates bitcoin value per line
void BitcoinExchange::processInput(const std::string &filename)
{
	// this function is basically: parse → validate → run → print → repeat
	std::ifstream file(filename.c_str());
	std::string line;
	size_t pos;
	std::string date;
	std::string valueStr;
	float value;
	float rate;

	// std::cout << "Processing file..." << std::endl;
	if (!file.is_open())
	{
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return;
	}
	std::getline(file, line); //skipping header (IMPORTANTTT)
	while (std::getline(file, line))
	{
		// std::cout << "Testing LINe???: " << line << std::endl;
		if (line.empty())
			continue;
		pos = line.find('|');
		// problem: cant handle "|" properly??????? why?
		// if (pos == std::npos)
		// {
		// 	std::cerr << "Error: << line << std::endl;
		// 	continue;
		// }
		if (pos == std::string::npos)
		{
			std::cerr << RED << "Error: bad input => " << RESET << line << std::endl;
			continue;
		}
		// split + trim
		date = trim(line.substr(0, pos));
		valueStr = trim(line.substr(pos + 1));
		if (!isValidDate(date))
		{
			std::cerr << RED << "Error: bad input => " << RESET << line << std::endl;
			continue;
		}
		if (!isValidValue(valueStr, value))
			continue;
		rate = getRate(date);
		if (rate < 0)
		{
			// no earlier date exists in DB
			std::cerr << RED << "Error: no valid date => " << RESET << line << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	file.close();
}
