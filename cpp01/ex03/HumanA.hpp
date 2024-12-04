/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:40:46 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 16:21:45 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
class Weapon;

class HumanA
{
    public:
        HumanA(std::string _name, Weapon& weapon);
        ~HumanA(void);
        void    attack(void);
    private:
        std::string _name;
        Weapon  &weapon;

};

#endif