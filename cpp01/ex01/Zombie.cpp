/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:29:06 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 12:59:07 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Default constructor called." <<std::endl;
    return ;
}

Zombie::Zombie(std::string) : _name(_name)
{
    std::cout << "Zombie \"" << this->_name << "\" Constructor called" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie \"" << this->_name << "\" Destructor called" << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ; 
}

void    Zombie::set_name(std::string name)
{
    this->_name = name;
    return ;
}

