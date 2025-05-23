/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:53:53 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/13 15:56:51 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

//this function has to find the first occurrence
//of the second parameter in the first parameter.

class NotFoundExeption : public std::exception
{
	public:
		virtual const char* what() const throw() { return ("Value not found in container :( "); }
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int n)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
	throw NotFoundExeption();
	return (it);
}
