/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:15:53 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/09 16:52:44 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat& Bureaucrat);

		class GTHExeption : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GTLExeption : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _signed;
		const int _gradeToExec;
		const int _gradeToSign;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
