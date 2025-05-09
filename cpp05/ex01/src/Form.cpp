/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:14:35 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/09 17:45:04 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	// Validate grades r within 1–150
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GTHException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GTLException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed),
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GTLException();
	_signed = true;
}

const char* Form::GTHException::what() const throw()
{
	return "Grade is too high :(";
}

const char* Form::GTLException::what() const throw()
{
	return "Grade is too low :(";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	//we need to print all Forms information
	os << "Form: " << f.getName() << " is " << (f.isSigned() ? "signed" : "not signed")
	<< ", requires grade " << f.getGradeToSign() << " to sign and grade "
	<< f.getGradeToExec() << " to execute.";
	return os;
}
