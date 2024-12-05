/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:27:04 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/05 16:44:21 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

// Create a program that takes three parameters:
// filename and two strings, s1 and s2.
// It will open the file <filename> and copies its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.

int main(int ac, char **av)
{
	std::string		if_content;

	if (ac != 4)
	{
		std::cout << "Not enough args. Please try again." <<std::endl;
		std::cout << "Usage: ./sedforlosers <filename ><s1> <s2>" << std::endl << std::endl;
		std::cout << "s1: The string to search for in the file." << std::endl;
		std::cout << "s2: The string to replace s1 with." << std::endl;
		return (1);
	}
	std::ifstream infile(av[1]);
	if (!infile)
	{
		std::cout << "Error opening file: " << av[1] << std::endl;
		return (1);
	}
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be an empty string.\n";
		return 1;
	}
	std::string line, res;
	size_t not_found = std::string::npos;
	while(std::getline(infile, line))
	{
		int i = 0;
		while ((i = line.find(s1, i)) != not_found) {
			res += line.substr(0, i);   // Add text before the match
			res += s2;                   // Add the replacement text
			line = line.substr(i + s1.length()); // Remove processed part
		}
		res += line;   // Add remaining text in the line
		res += '\n';
	}
	infile.close();
	std::string outfile_name = std::string(av[1]) + ".replace";
	std::ofstream outfile(outfile_name);
	if (!outfile) {
		std::cerr << "Skibidi Error creating file: " << outfile_name << std::endl;
		return 1;
	}
	outfile << res;
	outfile.close();

	std::cout << "YAYYYYYY replacement complete. Output written to: " << outfile_name << std::endl;	
	return(0);
}