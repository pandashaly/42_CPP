/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:43 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/01 16:01:47 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			j = 0;
			while (av[i][j])
				std::cout << (char) std::toupper(av[i][j++]);
		}
	}
	std::cout << std::endl;
	return (0);
}

/*
- Cpp uses <iostream> for input/output instead of <stdio.h> (e.g., std::cout vs printf).
- std::toupper() is part of <cctype>, works like toupper() in C but is safer with std::string.
- for (int i = 1; ...) declares 'i' inside the loop, scoped to it (C requires separate declaration).
- std::cout << chains outputs directly, unlike printf which needs format specifiers.
*/