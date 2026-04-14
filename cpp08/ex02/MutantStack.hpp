/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:05:35 by ssottori          #+#    #+#             */
/*   Updated: 2026/04/14 22:56:17 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <list>
#include <stack>
#include <deque>

//we are inheriting it from the std::stack and making the container iterable
//useful link:
//https://stackoverflow.com/questions/75093686/how-to-make-a-c-stack-container-iterable
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iter;

		//ocf
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack() {}

		//iterators
		iter begin() { return this->c.begin(); }
		iter end() { return this->c.end(); }
};
