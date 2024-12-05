/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:02:48 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 19:51:19 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void    Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	return ;
}

void    Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void    Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void    Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

// void	Harl::complain(std::string level)
// {
// 	void		(Harl::*func[4])(void);
// 	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

// 	func[0] = &Harl::_debug;
// 	func[1] = &Harl::_info;
// 	func[2] = &Harl::_warning;
// 	func[3] = &Harl::_error;

// 	for (size_t i = 0; i < levels->length(); i++)
// 	{
// 		if (level == levels[i])
// 		{	
// 			(this->*func[i])();
// 			return ;
// 		}
// 	}
// }

void Harl::complain(std::string level) 
{
	int i;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			Harl::_debug();
			std::cout << "[ INFO ]" << std::endl;
			Harl::_info();
			std::cout << "[ WARNING ]" << std::endl;
			Harl::_warning();
			std::cout << "[ ERROR ]" << std::endl;
			Harl::_error();
			break;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			Harl::_info();
			std::cout << "[ WARNING ]" << std::endl;
			Harl::_warning();
			std::cout << "[ ERROR ]" << std::endl;
			Harl::_error();
			break;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			Harl::_warning();
			std::cout << "[ ERROR ]" << std::endl;
			Harl::_error();
			break;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			Harl::_error();
			break;
		default:
			std::cout << "No Valid Level.\n";
			break;
	}
}