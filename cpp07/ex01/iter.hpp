/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:23:06 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 11:42:53 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>

void iter(T* arr, size_t len, void (*f)(const T&))
{
	if (arr == NULL || f == NULL)
		return ;
	for(size_t i = 0; i < len; i++)
		f(arr[i]);
}
