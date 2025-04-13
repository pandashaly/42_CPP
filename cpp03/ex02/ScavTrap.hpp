/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:09:15 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 00:22:56 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

//ScavTrap is a CHILD CLASS and it is INHERITING everything ClapTrap can do. YAY!
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& other); //copy
		ScavTrap& operator=(const ScavTrap& other); //copy assignment operator
		~ScavTrap();

		ScavTrap(std::string name);

		void guardGate();
		void attack(const std::string& target); //we are overriding attack

};

#endif
