/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:59:08 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/07 02:20:53 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
	Fixed();
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

	private:
	int _fixedpt;
	static const int    _bits = 8;
};

#endif