/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:53:53 by ssottori          #+#    #+#             */
/*   Updated: 2025/07/19 20:59:26 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <algorithm> //find - returns an iter to the 1st match, or the end iter if nothing is found. 
#include <vector>
#include <list>
#include <iostream>
#include <deque>
#include <sstream>

//this function has to find the first occurrence
//of the second parameter in the first parameter.

//function templates r cool, they r like blueprints for functions!

template <typename T>
typename T::const_iterator easyfind(const T& container, int n)
{
	typename T::const_iterator i = std::find(container.begin(), container.end(), n);
	if (i == container.end())
	{
		std::ostringstream oss;
		oss << "No occurance found for value: : " << n;
		throw std::logic_error(oss.str());
	}
	return (i);
}
