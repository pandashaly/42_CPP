/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:05:20 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 14:54:04 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found!";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
		}; // Known names that the Intern recognizes

	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	}; // Matching array of function pointers that return new form instances

	for (int i = 0; i < 3; i++) // serch for a name match
	{
		if (formName == formNames[i]) 
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target); //call the right create function
		}
	};

	std::cerr << "Intern: error — form '" << formName << "' does not exist." << std::endl;
	throw FormNotFoundException();
}

//Make form - eg menu and chef
//menu options: pizza, burger
//chef action:
//chef.cookPizza(target)
//chef.cookBurget(target)