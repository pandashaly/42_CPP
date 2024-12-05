/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:09:57 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 21:10:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	harl.complain("DEBUG");
    std::cout << "--------------------------------------" << std::endl;
	harl.complain("INFO");
    std::cout << "--------------------------------------" << std::endl;
	harl.complain("WARNING");
    std::cout << "--------------------------------------" << std::endl;
	harl.complain("ERROR");
	return (0);
}