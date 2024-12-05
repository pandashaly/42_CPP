/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:05:16 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 17:16:03 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA consructor for " << this->_name << " with weapon " << this->_weapon.getType() << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor for " << this->_name << " with weapon " << this->_weapon.getType() << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}