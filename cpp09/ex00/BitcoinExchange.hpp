/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:12:29 by ssottori          #+#    #+#             */
/*   Updated: 2026/04/22 13:30:51 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>


class BitcoinEx
{
	private:
	public:
		BitcoinEx();
		BitcoinEx(const BitcoinEx & other);
		BitcoinEx &operator=(const BitcoinEx &other);
		~BitcoinEx();

		int getValue();
		int getData();
		
		


		//exceptions - throw errors
};