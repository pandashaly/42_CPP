/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:32:29 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 02:20:52 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Orthodox Canonical Form

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called." << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap& other) //copy
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) //copy assignment operator
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
	return;
}
//-----------------

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack, not enough energy or HP!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " damage!" << std::endl;
	_energyPoints--;
	
}

void	ClapTrap::takeDamage(unsigned int dmg)
{
	_hitPoints -= dmg;
	if (_hitPoints < 0)
		_hitPoints = 0;

	std::cout << "ClapTrap " << _name << " takes " << dmg << " damage!" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int heals)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot heal. Not enough energy or HP!" << std::endl;
		return ;
	}
	_hitPoints += heals;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " heals for " << heals << " HP!" << std::endl;
}

