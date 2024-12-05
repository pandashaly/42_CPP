/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:36:24 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 16:49:12 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>
# include "HumanA.hpp"
# include "HumanB.hpp"


class Weapon
{
	public:
		Weapon(std::string _type);
		~Weapon(void);
		const std::string    &getType(void);
		void    setType(std::string _type);
	private:
		std::string _type;
};

#endif