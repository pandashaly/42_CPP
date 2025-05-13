/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:30:44 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 19:45:43 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _V(other._V) {}

Span &Span::operator=(const Span &other)
{
	if (thid != other)
	{
		_N = other._N;
		_V = other._V;
	}
	return this*
}

Span::~Span() {}

//member functions 
void Span::addNumber(int num)
{
	if (_V.size() >= _N)
		throw Span::SpanFullException();
	_V.push_back(num);
}
int Span::shortestSpan()
int Span::longestSpan()
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_V.size)
}
//void addManyNumbers()

