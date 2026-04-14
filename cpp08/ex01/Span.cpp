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

Span::Span() : _ms(0) {}

Span::Span(unsigned int N) : _ms(N) {}

Span::Span(const Span &other) : _ms(other._ms), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_ms = other._ms;
		_data = other._data;
	}
	return *this;
}

Span::~Span() {}

//member functions 
void Span::addNumber(int num)
{
	if (_data.size() >= _ms)
		throw Span::SpanFullException();
	_data.push_back(num);
}

int Span::shortestSpan()
{
	if (_data.size() < 2)
		throw NotEnoughNumsException();
	//sort array
	std::vector<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	int shawty = tmp[1] - tmp[0];
	//could also use STL algorithm std::adjacent_difference
	for (std::vector<int>::size_type i = 1; i < tmp.size() - 1; ++i)
	{
		int diff = tmp[i + 1] - tmp[i];
		if (diff < shawty)
			shawty = diff;
	}
	return shawty;
}

//last element - first element
int Span::longestSpan()
{
	if (_data.size() < 2)
		throw NotEnoughNumsException();
	int minVal = *std::min_element(_data.begin(), _data.end());
	int maxVal = *std::max_element(_data.begin(), _data.end());

	return maxVal - minVal;
}

void Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::size_t count = std::distance(begin, end);
	if (_data.size() + count > _ms)
		throw SpanFullException();

	_data.insert(_data.end(), begin, end);
}
//void addManyNumbers()

//exceptions
const char* Span::SpanFullException::what() const throw()
{
	return "Span is already full";
}

const char* Span::NotEnoughNumsException::what() const throw()
{
	return "Not enough numbers. No span can be found.";
}
