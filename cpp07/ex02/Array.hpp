/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:02:41 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 14:11:08 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

// Creates an array of n elements initialized by default.

template <class T>
class Array
{
	private:
		size_t _size;
		T* _arr;
	
	public:
	//-------- constructors & destructors --------
		Array() : _size(0) { _arr = new T[0]; };

		Array(unsigned int n) : _size(n) { _arr = new T[_size](); };

		Array(const Array& other) : _size(other._size)
		{
			_arr = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
		};
		
		~Array() { delete[] _arr; };
		
	//----------------operators --------------------
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _arr;
				_size = other._size;
				_arr = new T[_size]();
				for(size_t i = 0; i < _size; i++)
					_arr[i] = other._arr[i];
			}
			return *this;
		}

		T& operator[](unsigned int i)
		{
			if (i >= _size)
				throw (std::out_of_range("Index out of bonds"));
			return (_arr[i]);
		}

		const T& operator[](unsigned int i) const
		{
			if (i >= _size)
				throw std::out_of_range("Index out of bounds");
			return _arr[i];
		}

	//----------------member functions --------------------
		unsigned int size() const { return _size; };
};

