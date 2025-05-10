/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:01:55 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 11:42:45 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>


//return const to avoid unnecessary copies

template <typename A> //min
A const& min (A const& x, A const& y) { return ((x<y) ? x : y); }

template <typename Z> //max
Z const& max (Z const& x, Z const& y) { return ((x>y) ? x : y); }

template <typename S> //swap
void swap(S& x, S& y)
{
	S tmp = x;
	x = y;
	y = tmp;
}

#endif
