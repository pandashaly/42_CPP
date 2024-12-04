/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:16 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 16:13:59 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), weapon(weapon)
{
	std::cout << "HumanA consructor for " << this->_name << " with weapon " << this->weapon.getType() << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor for " << this->_name << " with weapon " << this->weapon.getType() << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}