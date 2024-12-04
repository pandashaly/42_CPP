/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:27:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 19:31:07 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// Create a program that takes three parameters:
// filename and two strings, s1 and s2.
// It will open the file <filename> and copies its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.

std::string    openFile(std::ifstream file)
{
	
}

// std::string     search_replace(std::string line, std::string s1)
// {

// }

int main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outfile_name;
	std::string		if_content;

	if (ac != 4)
	{
		std::cout << "Not enough args. Please try again." <<std::endl;
		std::cout << "Usage: ./sedforlosers <filename ><s1> <s2>" << std::endl << std::endl;
		std::cout << "s1: The string to search for in the file." << std::endl;
		std::cout << "s2: The string to replace s1 with." << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (!infile)
	{
		std::cout << "Error opening file: " << av[1] << std::endl;
		return (1);
	}
	else
	{
		int i = 0;
		std::string outfile_name = std::string(av[i]) + ".replace";
		std::ofstream outfile(outfile_name);
		if (!outfile)
		{
		std::cout << "Error creating file: " << outfile_name << std::endl;
		return 1;
		}
		std::string	line;
		while (std::getline(infile, line))
		{
			outfile << line << std::endl;
			std::cout << line << std::endl;
		}
	}
	infile.close();
	
	return(0);
}