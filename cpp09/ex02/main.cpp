/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:06:48 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 19:15:19 by ssottori         ###   ########.fr       */
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

//./PmergeMe $(jot -r 20 1 100 | tr '\n' ' ')

// ./PmergeMe 3 5 9 7 4
// ./PmergeMe 8 3 1 9 2 7 4 6 5
// ./PmergeMe 10 9 8 7 6 5 4 3 2 1
// ./PmergeMe 1 2 3 4 5
// ./PmergeMe 42
// ./PmergeMe 3 3 2
// ./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " "`
