/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:28:46 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/12 16:52:55 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>


class Fixed
{
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &other);
		~Fixed();

		//mathmath operators
		Fixed& operator=(const Fixed& other); // copies rawbits from other to *this
		Fixed operator+(const Fixed& other) const; //no & because it doesnt modify *this
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		//increment/decrement operators
		Fixed& operator ++ (void);
		Fixed& operator -- (void);
		Fixed operator++(int);
		Fixed operator -- (int);

		//comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		//static min max
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed &min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed &max(const Fixed& a, const Fixed& b);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
	private:
		int _rawBits;
		static const int _fractionalBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &val);

#endif