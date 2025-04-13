/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:07:05 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 00:43:47 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() 
{
	ClapTrap a("Robin");
    ScavTrap b("Batman");
	std::string c = "Joker";

	ClapTrap d(a);
	ClapTrap e;
	e = a;
	a.attack(c);
    b.attack(c);
	a.takeDamage(5);
	a.beRepaired(3);

    b.takeDamage(30);
	b.beRepaired(15);

	a.takeDamage(10);    // should bring HP to 0
	a.attack(c);     // should fail due to 0 HP
	a.beRepaired(2);     // should also fail

    b.guardGate();

	return 0;
}
