/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:37:17 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 11:42:49 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void    ftPrint(const T &x)
{
	std::cout << x << " ";
}

int main()
{
	std::cout << "------- int array test --------" << std::endl;

	int intArr[] = {0, 1, 2, 3, 4, 5};
	size_t arrLen = sizeof(intArr) / sizeof(intArr[0]);
	::iter(intArr, arrLen, ftPrint); // Output: 1 2 3 4 5
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "------- str array test --------" << std::endl;

	std::string strArr[] = {"hello", "world", "welcome", "to", "cpp", "templates!"};
	size_t strArrLen = sizeof(strArr) / sizeof(strArr[0]);
	::iter(strArr, strArrLen, ftPrint);
		std::cout << std::endl;

	return 0;
}
