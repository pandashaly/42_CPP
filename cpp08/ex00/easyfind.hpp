/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:24:29 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 15:29:32 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

//this function has to find the first occurrence
//of the second parameter in the first parameter.

template <typename T>
int easyfind(const T& arr, int find)
{
	typename T::iter it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
	throw NotFoundExeption();
	return (it);
}
