/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:51:29 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 16:48:52 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(std::string _type) : _type(_type)
{
    std::cout <<  "Weapon constructor called for weapon type " << this->_type << std::endl;
    return ;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon destructor called for weapon type " << this->_type << std::endl;
    return ;
}

const std::string    &Weapon::getType(void)
{
    return (this->_type);
}

void    Weapon::setType(std::string _type)
{
    this->_type = _type;
    return ;
}
