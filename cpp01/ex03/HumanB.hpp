/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:41:54 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 17:09:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
class Weapon;

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack();
		void	setWeapon(Weapon &weapon);
	private:
		std::string	_name;
		Weapon		*weapon;
};

#endif