/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:32:16 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 17:42:15 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector> //resizable array

//This project is about templated containers, iterators and algorithms in CPP.
class Span
{
	private:
		unsigned int _N;
		
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
		void addNumber();

		//exceptions
		
};

//type of vector cant be changed after its been declared
//vector<type> vectorName
//.front()	.back() to access vector 
//.at() function is often preferred over square
//brackets [] to access or change a value of a vector
//push_back() and pop_back() to add or remove vector elements