/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:06:48 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 21:18:31 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc,char **argv)
{
	PmergeMe	pmerge;

	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		pmerge.parse(argv);
		pmerge.run();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}


//TESTS

//./PmergeMe $(jot -r 20 1 100 | tr '\n' ' ')

// ./PmergeMe 3 5 9 7 4
// ./PmergeMe 8 3 1 9 2 7 4 6 5
// ./PmergeMe 10 9 8 7 6 5 4 3 2 1
// ./PmergeMe 1 2 3 4 5
// ./PmergeMe 42
// ./PmergeMe 3 3 2

// # normal cases
// ./PmergeMe 3 5 9 7 4
// ./PmergeMe 8 3 1 9 2 7 4 6 5
// ./PmergeMe 10 9 8 7 6 5 4 3 2 1
// ./PmergeMe 1 2 3 4 5

// # edge cases
// ./PmergeMe 42
// ./PmergeMe 1 1 1 1
// ./PmergeMe 3 3 2
// ./PmergeMe 2 1
// ./PmergeMe 2147483647

// # errors
// ./PmergeMe
// ./PmergeMe -1 2 3
// ./PmergeMe 1.5
// ./PmergeMe abc
// ./PmergeMe 2147483648

// # big test
// ./PmergeMe $(jot -r 3000 1 10000 | tr '\n' ' ')
// ./PmergeMe $(jot -r 20 1 100 | tr '\n' ' ')
