/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:14:35 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/09 16:58:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
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

void Form::beSigned(const Bureaucrat& Bureaucrat)
{
    
}

const char* Form::GTHExeption::what() const throw()
{
	return "Grade is too high :(";
}

const char* Form::GTLExeption::what() const throw()
{
	return "Grade is too low :(";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f)
{
    //we need to print all Forms information
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
