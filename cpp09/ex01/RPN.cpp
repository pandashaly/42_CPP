/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:27:53 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 15:47:48 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//OCF
RPN::RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}
RPN::~RPN() {}

//----------------

// checks if token is an operator we support
bool RPN::isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

//math
int RPN::doOperation(int a, int b, const std::string &op)
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error"); // can NOTTT be boehterd to debug infinity
		return a / b;
	}
	throw std::runtime_error("Error");
}

void RPN::calculate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	int a;
	int b;
	int result;

	while (iss >> token)
	{
		// std::cout << "token: " << token << std::endl; //debugginggg
		// subject says numbers used as tokens are less than 10,
		// so keeping it to single digit numbers is enough
		if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(token[0] - '0');
			// std::cout << "push: " << (token[0] - '0') << std::endl;
		else if (isOperator(token))
		{
			// not enough operands = invalid expression
			if (_stack.size() < 2)
				throw std::runtime_error("Error");

			//_stack.pop();
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			//this should be the correct oderrr??

			result = doOperation(a, b, token);
			// std::cout << a << " " << token << " " << b << " = " << result << std::endl;
			_stack.push(result);
		}
		else
			throw std::runtime_error("Error");
			// didn't work because I forgot spaces exist -__-
			// if (token == "(" || token == ")")
			// 	continue;
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	std::cout << _stack.top() << std::endl;
}
