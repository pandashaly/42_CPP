/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:32:16 by ssottori          #+#    #+#             */
/*   Updated: 2026/04/15 11:36:50 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector> //resizable array

//This project is about templated containers, iterators and algorithms in CPP.
class Span
{
	private:
		unsigned int _ms;
		std::vector<int> _data;
		
	public:
		Span();
		Span(const Span &other);
		Span(unsigned int N);
		Span &operator=(const Span &other);
		~Span();

		//member functions 
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		//exceptions
		class SpanFullException : public std::exception {
			public:
				const char*  what() const throw();
		};
		//{ return "Span is already full"; }

		class NotEnoughNumsException : public std::exception {
			public:
				const char* what() const throw();
		};
};
//{ return "Not enought numbers. No span can be found."; }

//type of vector cant be changed after its been declared
//vector<type> vectorName
//.front()	.back() to access vector 
//.at() function is often preferred over square
//brackets [] to access or change a value of a vector
//push_back() and pop_back() to add or remove vector elements
