/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:00:41 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 00:00:39 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

//ShrubberyCreationForm: Required grades: sign 145, exec 137
//Creates a file <target>_shrubbery in the working directory
//and writes ASCII trees inside it.

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GTLException();
	
	std::ofstream file((_target + "_shrubbery").c_str());
	// c_str for converting std::string to const char* for ofstream -> required by C++98
	if (file.is_open())
	{
		file << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
		file << "⣿⣿⣿⡿⠃⠙⣿⣿⠟⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠹⣿⣿⣿⣿⣿" << std::endl;
		file << "⣿⣿⣭⠀⠀⠀⣬⣿⣿⣄⠀⠀⣿⡿⠋⠀⠙⢿⣿⡿⠁⠙⣧⡀⠀⠘⢿⣿⣿⣿" << std::endl;
		file << "⣿⡿⠋⠀⢀⣼⢻⣷⣄⠀⠠⠶⠿⣶⠂⢀⣴⣞⣋⠀⠀⠀⣬⣿⣦⡸⣿⣿⣿⣿" << std::endl;
		file << "⣿⣀⠀⣠⡾⠁⠀⠙⠿⣧⣀⣠⡾⠃⠀⠀⠈⣽⠋⠀⠀⠀⠹⣧⡉⠉⠀⣉⣛⣿" << std::endl;
		file << "⣿⠿⠿⢿⡶⠀⠀⠀⢲⣿⡿⠿⣦⡄⣀⡴⠛⠁⠀⠀⠀⠀⠀⠈⠻⣦⡀⠙⢿⣿" << std::endl;
		file << "⣿⣠⣴⠟⠁⠀⠀⠀⠀⠙⠳⣶⣟⠛⠛⠛⢳⡦⠀⠀⠀⠀⠀⠀⣤⣤⣽⡷⠦⣿" << std::endl;
		file << "⣿⣿⠶⢶⠆⠀⠀⠀⠀⠰⣶⠶⠿⠷⣦⣴⠟⠀⠀⠀⠀⠀⠀⠀⠹⣦⣤⣤⣤⣿" << std::endl;
		file << "⣿⣿⣴⠋⠀⠀⠀⠀⠀⠀⠈⠳⣶⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿" << std::endl;
		file << "⣿⣋⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣙⣷⠦⣤⣤⣤⣤⣤⣤⣤⣤⠶⠶⣾⣿⣿⣿" << std::endl;
		file << "⣿⣿⠙⠛⢻⡶⠶⠶⠶⣶⠞⠛⣿⣿⣿⠀⠀⠈⣿⡏⠀⠀⢸⡇⠀⠀⣿⣿⣿⣿" << std::endl;
		file << "⣿⣿⠀⠀⢸⠇⠀⠀⠀⢻⡄⠀⣿⣿⣿⠀⠀⠀⣿⡇⠀⠀⢸⡇⠀⠀⣿⣿⣿⣿" << std::endl;
		file << "⣿⣿⠀⠀⣾⠀⠀⠀⠀⢸⣇⣀⣿⣿⣿⠀⠀⠀⣿⡇⠀⠀⠸⣇⠀⠀⣿⣿⣿⣿" << std::endl;
		file << "⣿⣿⣤⣤⣿⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣶⣶⣶⣿⡇⠀⠀⠀⣿⣀⣀⣿⣿⣿⣿" << std::endl;
		file << "⣿⣿⣿⣿⣿⣤⣤⣤⣤⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿" << std::endl;
		file.close();
	}
}
