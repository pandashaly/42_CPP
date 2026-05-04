/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:05:12 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 15:28:15 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cctype>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		bool isOperator(const std::string &token);
		int doOperation(int a, int b, const std::string &op);
		void calculate(const std::string &expression);
};

#endif
