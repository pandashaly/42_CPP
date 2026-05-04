/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:05:19 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 15:40:26 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Reverse Polish Notation ...(why is this even a thing???)
// Normal math you write like this: 3 + 4. 
// The operator sits between the numbers — that's called infix notation. 
// RPN puts the operator after the numbers: 3 4 +. 
//math hurts my head :(

#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try
	{
		rpn.calculate(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

//from the subject pdf
// Here is an example of standard usage:
// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// $> ./RPN "7 7 * 7 -"
// 42
// $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// $> ./RPN "(1 + 1)"
// Error


// more tests....
// should give 42, 42 ,  0 ,  42 ,  42 , and  15 
// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// ./RPN "7 7 * 7 -"
// ./RPN "1 2 * 2 / 2 * 2 4 - +"
// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// ./RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
// ./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"

// ./RPN "(1 + 1)"
// ./RPN "1 +"
// ./RPN "+"
// ./RPN "1 2 3 +"
// ./RPN "1 2 a +"
// ./RPN "4 0 /"

