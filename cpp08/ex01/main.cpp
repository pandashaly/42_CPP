/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:51:40 by ssottori          #+#    #+#             */
/*   Updated: 2025/06/17 22:11:21 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	//subject test
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "-------------------------" << std::endl;

	//span of 10000
	try
	{
		Span sp(13000);
		std::vector<int> nums;

		for (int i = 0; i < 13000; ++i)
			nums.push_back(i);

		sp.addManyNumbers(nums.begin(), nums.end());

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;

	//span of size 2 (should throw)
	//If there are no numbers stored,
	//or only one, no span can be found. Thus, throw an exception
	try {
		Span shortsp = Span(2);
		shortsp.addNumber(13);
		//shortsp.addNumber(15);
		std::cout << shortsp.shortestSpan() << std::endl;
		std::cout << shortsp.longestSpan() << std::endl;
		std::cout << "-------------------------" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;

	return 0;
}

// Should output:
// $> ./ex01
// 2
// 14
// $>
