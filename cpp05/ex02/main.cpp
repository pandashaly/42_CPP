/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:23:47 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 00:28:43 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"


//A grade ranges from 1 (highest possible grade) to 150 (lowest possible grade).
int main()
{
	Bureaucrat high("High", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 150);

	std::cout << "\nShrubbery Test 🌲" << std::endl;
	std::cout << "-------------------------" << std::endl;
	ShrubberyCreationForm shrubbery("trees");
	std::cout << shrubbery << std::endl;
	std::cout << std::endl;

	try {
		high.executeForm(shrubbery);
	} catch (std::exception &e) {
		std::cout << "[Shrubbery] Execution failed: " << e.what() << std::endl;
	}

	high.signForm(shrubbery);
	high.executeForm(shrubbery);

	//===========================
	std::cout << "\nRobotomy Test 🤖" << std::endl;
	std::cout << "-------------------------" << std::endl;
	RobotomyRequestForm robotomy("Bender");
	std::cout << robotomy << std::endl;
	std::cout << std::endl;

	low.signForm(robotomy);
	low.executeForm(robotomy);

	mid.signForm(robotomy);
	mid.executeForm(robotomy);

	//==============================
	std::cout << "\nPresidential Pardon Test 🤵‍♂️" << std::endl;
	std::cout << "-------------------------" << std::endl;
	PresidentialPardonForm pardon("Luigi Mangione");
	std::cout << pardon << std::endl;
	std::cout << std::endl;

	mid.signForm(pardon);
	mid.executeForm(pardon);

	high.signForm(pardon);
	high.executeForm(pardon);
}
