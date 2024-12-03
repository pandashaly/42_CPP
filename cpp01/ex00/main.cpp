/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:56:58 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/03 01:33:53 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "Creating a zombie on the heap using newZombie:" << std::endl;
    Zombie* heap = newZombie("HeapZ");
    heap->announce();
    delete heap;

    std::cout << "\nCreating a Zombie on the stack using randomChump:" << std::endl;
    randomChump("StackZ");

    return (0);
}