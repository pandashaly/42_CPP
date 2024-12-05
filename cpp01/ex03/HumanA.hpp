/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:40:46 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 19:41:48 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"
#include <string>
#include <iostream>
class Weapon;

class HumanA
{
	public:
		//constructors
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
			//member function
		void    attack();
	private:
		std::string _name;
		Weapon  &_weapon;
};

#endif