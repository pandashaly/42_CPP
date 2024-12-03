/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:58:12 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/03 01:31:59 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <new>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void    announce(void);
	private:
		std::string _name;
};

Zombie*	newZombie(std::string name); //1 heap -delete
void	randomChump(std::string name); //2 stack - deletes itself

//1 It creates a zombie, name it, and return it so you can use it outside of the function scope.
//2 It creates a zombie, name it, and the zombie announces itself.

// The Stack:
// Temporary memory (like your plate for cookies).
// When you create a Zombie on the stack, it disappears when the function ends.
// The Heap:
// Permanent memory (like a cookie box).
// Zombies on the heap stick around until you destroy them (using delete).

#endif
