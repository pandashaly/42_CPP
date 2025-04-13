/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:39:31 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 01:36:25 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Orthodox Canonical Form

FragTrap::FragTrap(): ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Default FragTrap constructor called." << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) //copy
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) //copy assignment operator
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) // u can only use initializer lists to initialize members that belong to the current class in the initializer list.
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

//----------------------
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " high fives for VENGENCE" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack, not enough energy or HP!" << std::endl;
		return;
	}

	std::cout << "FragTrap " << this->_name << " drops from the shadows and strikes " << target
			<< " using ULT, dealing " << this->_attackDamage << " damage! VENGENCE!" << std::endl;
	this->_energyPoints--;
}