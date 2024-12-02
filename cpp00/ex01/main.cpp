/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:26:55 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/02 00:48:53 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#define H0 "=====================================================\n"
#define H1 "|    Index   | First Name | Last Name  | Nick Name  |\n"
#define H2 "|            Enter new contact information          |\n"
#define H3 "|             *** My Awesome PhoneBook ***          |\n"
#define H4 "|                  Contact information              |\n"
#define CLR "\e[1;1H\e[2J"

void	take_input(std::string *input)
{
	std::getline(std::cin, *input);
	while(input->empty())
	{
		std::cout << "Field cannot be empty. Please enter again:";
		std::getline(std::cin, *input);
	}
}

void	add_prompt(PhoneBook &pb)
{
	std::string fn, ln, nn, pn, ds;
	std::cout << CLR;
	std::cout << H0 << H2 << H0;
	std::cout << "Enter information for new contact:" << std::endl;
	std::cout << "First Name: ";
	take_input(&fn);
	std::cout << "Last Name: ";
	take_input(&ln);
	std::cout << "Nickname: ";
	take_input(&nn);
	std::cout << "Phone Number: ";
	take_input(&pn);
	std::cout << "Darkest Secret: ";
	take_input(&ds);
	pb.createCT(fn, ln, nn, pn, ds);
	return ;
}

void	contact_info(Phonebook &pb, int i)
{
	std::cout << CLR;
	std::cout << H0 << H4 << H4;
	pb.print(i);
	std::cout << std::endl << "Press enter to continue..." << std::endl;
	std::cin.get();
}

int	main(void)
{
	PhoneBook		pb;
	std::string		input;
	while(1)
	{
		str::cout << CLR
		str::cout << H0 << H3 << H0
		str::cout << "Enter one of the following instruction (ALL CAPS)." << std::endl;
		str::cout << "ADD, SEARCH or EXIT" << std::endl;
		str::cout << "PhoneBook> ";
		std::getline(std::cin, input);
		if (input == "ADD") 
			add_prompt(pb);
		else if (input == "SEARCH")
			search_prompt(pb);
		else if (input == "EXIT")
			return (0);
		std::cout << "PhoneBook> ";
	}
}