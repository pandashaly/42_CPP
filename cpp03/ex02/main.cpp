/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:39:38 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 12:05:56 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "🦇 On a dark night, the Bat symbol looms in the sky...\n" << std::endl;

	ClapTrap a("Alfred");
	ScavTrap r("Robin");
	FragTrap b("Batman");
	std::string enemy = "Bane";

	std::cout << std::endl;
	b.highFivesGuys();
	std::cout << std::endl;

	std::cout << "Alfred opens the door to find " << enemy << " standing on the doorstep..." << std::endl;
	a.attack(enemy); // does like 0 damage
	a.takeDamage(20); //HP should hit 0 - Poor Alfred
	a.attack(enemy); //should fail, hes dying.
	r.attack(enemy);
	r.guardGate();
	a.beRepaired(5); //should fail, he's dead
	b.attack(enemy);

	std::cout << std::endl;
	std::cout << enemy << " strikes back!" << std::endl;
	r.takeDamage(15);
	b.takeDamage(40);

	r.guardGate();
	a.beRepaired(2); //should fail, ALfred is still Dead
	std::cout << "The duo do everything they can to heal Alfred, but its hopeless..." << std::endl;
	r.beRepaired(10);
	b.beRepaired(30);
	b.highFivesGuys();

	std::cout << std::endl;
	std::cout << "Batman is filled with burning rage at Alfreds death..." << std::endl;
	std::cout << "THIS ENDS NOW! 🔥" << std::endl;
	r.attack(enemy);
	b.attack(enemy);

	std::cout << std::endl;
	std::cout << "The fall of " << enemy << " and the rise of the Dark Knight!" << std::endl;
	std::cout << std::endl;
	return 0;
}
