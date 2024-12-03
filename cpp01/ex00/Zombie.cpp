/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:04:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/03 01:24:37 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout <<"Zombie \"" << this->_name << "\" Constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << this->_name << "\" Destructor called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Constructor -> giving the zombie life - or in this case, creating the object
// Destructor -> destroying the object 