/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:19:11 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 22:31:44 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main(int argc, char **argv) 
// {
// 	try
// 	{
// 		if (argc != 2)
// 			throw std::invalid_argument("this program takes 1 paramater");
// 		std::cout << std::fixed << std::setprecision(1);
// 		ScalarConverter::convert(argv[1]);
// 	} 
// 	catch (const std::exception& e)
// 		{std::cout << e.what() << '\n';}
// 	return 0;
// }

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
