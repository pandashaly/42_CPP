/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:11:38 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 21:24:50 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.loadDB("data.csv");
	btc.processInput(argv[1]);

	return 0;
}

//eval tests
// date | value
// 2011-01-03 | 2
// 2011-01-03 | -1
// bad input
// 2010-01-01 | 5
