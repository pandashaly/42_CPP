/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:02:59 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 20:15:11 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void    complain(std::string level, std::string filter);
	private:
		void    _debug();
		void    _info();
		void    _warning();
		void    _error();
		
};

int	get_level(std::string level);

#endif