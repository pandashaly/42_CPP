/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:05:37 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 00:37:53 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

//The intern has no name, no grade, and no unique characteristics.
//The only thing bureaucrats care about is that they do their job.

class Intern
{
	private:
		AForm* createShrubberyForm(const std::string& target);
		AForm* createRobotomyForm(const std::string& target);
		AForm* createPresidentialForm(const std::string& target);
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif