/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:00:44 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/03 01:31:00 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie randomChump(name);
	randomChump.announce();
}

// void randomChump(std::string name) {
//     Zombie zombie(name); // Create on the stack
//     zombie.announce(); // Zombie announces itself
// }