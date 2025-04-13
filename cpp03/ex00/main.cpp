/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:06:11 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/12 19:05:39 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
	ClapTrap a("Batman");
	std::string b = "Joker";

	ClapTrap c(a);
	ClapTrap d;
	d = a;
	a.attack(b);
	a.takeDamage(5);
	a.beRepaired(3);

	a.takeDamage(10);    // should bring HP to 0
	a.attack(b);     // should fail due to 0 HP
	a.beRepaired(2);     // should also fail

	return 0;
}
