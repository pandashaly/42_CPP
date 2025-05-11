/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:23:47 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 15:11:56 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

//A grade ranges from 1 (highest possible grade) to 150 (lowest possible grade).
int main()
{
	Intern bob;
	AForm* form = NULL;
	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("employee", 50);

	std::cout << "\nIntern creates forms" << std::endl;
	std::cout << "-------------------------" << std::endl;
	try {
		form = bob.makeForm("robotomy request", "George");
		delete form;

		form = bob.makeForm("shrubbery creation", "Carlos");
		delete form;

		form = bob.makeForm("presidential pardon", "Lewis");
		delete form;

		// This should fail
		form = bob.makeForm("random request", "Frank");
		delete form;
	} catch (std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	//===========================
	std::cout << "\nForm Creation and action" << std::endl;
	std::cout << "-------------------------" << std::endl;
	form = bob.makeForm("presidential pardon", "Jake");

	try {
		form->beSigned(boss);        // should succeed (PP needs grade 25 to sign)
		boss.executeForm(*form);
	} catch (std::exception& e) {
		std::cerr << "Action failed: " << e.what() << std::endl;
	}
	delete form;

	std::cout << "\nForm Creation and action" << std::endl;
	std::cout << "-------------------------" << std::endl;
	form = bob.makeForm("presidential pardon", "Jake");

	try {
		form->beSigned(employee);        // should fail (PP needs grade 25 to sign)
		employee.executeForm(*form);
	} catch (std::exception& e) {
		std::cerr << "Action failed: " << e.what() << std::endl;
	}
	delete form;

	return 0;
}
