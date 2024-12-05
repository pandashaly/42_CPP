/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:09:57 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 21:25:47 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
		return (std::cout << "Usage: ./harlFilter \"level\"\n", EXIT_FAILURE);
	std::string input = av[1];
	Harl        harl;

	harl.complain(input);

	return EXIT_SUCCESS;
}