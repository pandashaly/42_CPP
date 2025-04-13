/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:25:54 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/12 20:12:28 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		//Orthodox Canonical Form (as required by PDF)
		ClapTrap();
		ClapTrap(const ClapTrap& other); //copy
		ClapTrap& operator=(const ClapTrap& other); //copy assignment operator
		~ClapTrap();

		ClapTrap(std::string name);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string _name;
		int _hitPoints; //10
		int _energyPoints; //10
		int _attackDamage; //0
};

#endif