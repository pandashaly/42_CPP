/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:07:38 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 02:20:45 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Orthodox Canonical Form

ScavTrap::ScavTrap(): ClapTrap("Default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called." << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) //copy
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) //copy assignment operator
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) // u can only use initializer lists to initialize members that belong to the current class in the initializer list.
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

//----------------------
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode! Must Protect Gotham!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack, not enough energy or HP!" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< " using ULT, dealing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

//Why we are overwriting the attack function
// class Animal {
// public:
//     void speak() { std::cout << "Animal makes sound\n"; }
// };

// class Dog : public Animal {
// public:
//     void speak() { std::cout << "Dog barks\n"; }  // override
// };
// Even though Dog inherits speak() from Animal, it needs to make a different sound...bc a dog is not just any animal.