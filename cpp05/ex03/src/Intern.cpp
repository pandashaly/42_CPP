/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:05:20 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 00:38:34 by ssottori         ###   ########.fr       */
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

AForm* makeForm(const std::string& formName, const std::string& target)
{
	
}

// the intern has one key ability: the makeForm() function.
//This function takes two strings as parameters: the first one represents the name of a form,
//and the second one represents the target of the form.
//It returns a pointer to a AForm object (corresponding to the form name passed as a parameter),
//with its target initialized to the second parameter.
// It should print something like:
//    Intern creates <form>
// If the provided form name does not exist, print an explicit error message.