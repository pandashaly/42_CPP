/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:59:22 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 13:25:55 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Create a horde of Zombiessss" << std::endl;
		std::cout << "./moarbrainz <zombie_name> <quantity>" << std::endl;
		return (1);
	}

	std::string name = av[1];
	int n = std::atoi(av[2]);

	if (n < 1)
	{
		std::cout << "You have to rise at least 1 zombie :(" << std::endl;
		return (1);
	}

	Zombie  *horde = zombieHorde(n, name);
	std::cout << "Creating a horde of " << n << " zombies named " << name << std::endl;
	std::cout << n << " zombies have risen!" << std::endl;
	if (horde)
	{
		for (int i = 0; i < n; i++)
			horde[i].announce();
		std::cout << "I will bury them again...." << std::endl;
		delete [] horde;
		std::cout << "All " << n << " zombies have been buried!" << std::endl;
	}
	else
		std::cout << "Failed to rise zombies - Couldn't create horde..." << std::endl;
	return (0);
}