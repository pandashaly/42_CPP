/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:24:31 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 23:39:28 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GTHExeption : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GTLExeption : public std::exception
	{
		public:
			const char* what() const throw();
	};

	private:
	const std::string _name;
	int _grade;
};

// External overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif