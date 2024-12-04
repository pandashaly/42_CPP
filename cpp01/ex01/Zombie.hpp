/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:28:59 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 12:58:25 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cctype>

class Zombie
{
    public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void    announce(void);
    void    set_name(std::string name);
    
    private:
		std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif