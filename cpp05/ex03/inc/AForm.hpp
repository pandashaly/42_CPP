/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:15:53 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/09 17:34:44 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat& Bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0; //every child class will override this

		class GTHException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GTLException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
