/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:23:47 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 00:39:00 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


//A grade ranges from 1 (highest possible grade) to 150 (lowest possible grade).
int main()
{
	std::cout << "\nTesting valid form + bureaucrat" << std::endl;
	std::cout << "-------------------------" << std::endl;
	try
	{
		Bureaucrat bond("Bond 007", 1);
		std::cout << bond << std::endl;

		//AForm ts("TopSecret", 50, 25);
		//std::cout << ts << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	// // =================================
	// std::cout << "\nTesting signing" << std::endl;
	// std::cout << "----------------------------" << std::endl;

}
