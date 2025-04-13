/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:39:28 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 01:36:02 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap& other); //copy
		FragTrap& operator=(const FragTrap& other); //copy assignment operator
		~FragTrap();

		FragTrap(std::string name);

		void attack(const std::string& target); //we are overriding attack again
		void highFivesGuys(void);
};

#endif
