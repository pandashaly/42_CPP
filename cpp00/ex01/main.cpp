/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:26:55 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/02 02:12:27 by ssottori         ###   ########.fr       */
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

void	contact_info(PhoneBook &pb, int i)
{
	std::cout << CLR;
	std::cout << H0 << H4 << H4;
	pb.print_deets(i);
	std::cout << std::endl << "Press enter to continue..." << std::endl;
	std::cin.get();
}

void	search_prompt(PhoneBook &pb)
{
	int			i;
	std::string in;

	std::cout << CLR;
	std::cout << H0 << H1 << H0;
	i = 0;
	while (i < pb.get_size())
	{
		pb.print_sum(i);
		i++;
	}
	std::cout << H0;
	std::cout << "Enter contact index or EXIT:" << std::endl << "PhoneBook> ";
	while (1)
	{
		std::getline(std::cin, in);
		if (in == "EXIT")
			return ;
		else if ((in.length() != 1) || !(in[0] >= 49 && in[0] <= 58))
			std::cout << "Index is one digit between 1 - 8" << std::endl << "PhoneBook> ";
		else if (in[0] - 48 > pb.get_size())
			std::cout << "No contact at index " << in[0] - 48 << std::endl << "PhoneBook> ";
		else
			break ;
	}
	contact_info(pb, in[0] - 48 - 1);
}

int	main(void)
{
	PhoneBook		pb;
	std::string		input;
	while(1)
	{
		std::cout << CLR;
		std::cout << H0 << H3 << H0;
		std::cout << "Enter one of the following instruction (ALL CAPS)." << std::endl;
		std::cout << "ADD, SEARCH or EXIT" << std::endl;
		std::cout << "PhoneBook> ";
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