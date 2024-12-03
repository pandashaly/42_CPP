/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:26:55 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/03 17:55:35 by ssottori         ###   ########.fr       */
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

void	validateInput(std::string *input)
{
	//std::getline(std::cin, *input);
	if (!std::getline(std::cin, *input)) 
		{
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting...\n";
				exit(0);
			}
		}
	while(input->empty())
	{
		std::cout << "Field cannot be empty. Please enter again:";
		std::getline(std::cin, *input);
	}
}

bool	validNumber(const std::string &num)
{
	if (num.empty())
		return false;
	size_t start = 0;
	for (size_t i = start; i < num.length(); ++i)
	{
		if (!isdigit(num[i]))
			return false; // Invalid character found
	}
	return true;
}

void takeNumber(std::string &num)
{
	while (true)
	{
		//std::getline(std::cin, num);
		if (!std::getline(std::cin, num)) 
		{
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting...\n";
				break;
			}
		}
		if (validNumber(num))
			break;

		std::cout << "Invalid phone number. Please try again. (Digits only)\n";
		std::cout << "Phone Number: ";
	}
}


void	add(PhoneBook &pb)
{
	std::string fn, ln, nn, pn, ds;
	std::cout << CLR;
	std::cout << H0 << H2 << H0;
	std::cout << "Enter information for new contact: \n";
	std::cout << "First Name: ";
	validateInput(&fn);
	std::cout << "Last Name: ";
	validateInput(&ln);
	std::cout << "Nickname: ";
	validateInput(&nn);
	std::cout << "Phone Number: ";
	takeNumber(pn);
	std::cout << "Darkest Secret: ";
	validateInput(&ds);
	pb.createCT(fn, ln, nn, pn, ds);
	return ;
}

void	contact_info(PhoneBook &pb, int i)
{
	std::cout << CLR;
	std::cout << H0 << H4 << H0;
	pb.print_deets(i);
	std::cout << std::endl << "Press enter to continue..." << std::endl;
	std::cin.get();
}

void	search(PhoneBook &pb)
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
		//std::getline(std::cin, in);
		if (!std::getline(std::cin, in)) 
		{
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting...\n";
				break;
			}
		}
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

		if (!std::getline(std::cin, input)) 
		{
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting...\n";
				break;
			}
		}
		//std::getline(std::cin, input);
		//validateInput(&input);
		// if (input.empty())
		// {
		// 	std::cout << "Invalid input. Please try one of the options above." << std::endl;
		// 	continue;
		// }
		if (input == "ADD") 
			add(pb);
		else if (input == "SEARCH")
			search(pb);
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		std::cout << "PhoneBook> ";
	}
}