/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:11:03 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 16:16:41 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), weapon(NULL)
{
	std::cout << "HumanB consructor for " << this->_name << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destructor for " << this->_name << std::endl;
	return ;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->_name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->_name << " tried to attack but has no weapon..." << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	return ;
}