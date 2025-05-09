/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:23:47 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/09 16:06:02 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


//A grade ranges from 1 (highest possible grade) to 150 (lowest possible grade).

int main()
{
	std::cout << "\nTesting valid construction" << std::endl;
	std::cout << "-------------------------" << std::endl;

	try
	{
		Bureaucrat lilo("Lilo", 1);
		std::cout << lilo << std::endl;

		Bureaucrat stitch("Stitch", 150);
		std::cout << stitch << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	// =================================
	std::cout << "\nTesting invalid construction" << std::endl;
	std::cout << "----------------------------" << std::endl;
	
	try
	{
		Bureaucrat lilo("Lilo", 0);
		std::cout << lilo << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat stitch("Stitch", 151);
		std::cout << stitch << std::endl;
	}
	catch (std::exception& e) {
		std::cout <<"Exception caught: " << e.what() << std::endl;
	}
	// =================================
	std::cout << "\nTesting Increment and Decrement" << std::endl;
	std::cout << "----------------------------" << std::endl;

	try
	{
		Bureaucrat lilo("Lilo", 2);
		std::cout << lilo << std::endl;
		lilo.incrementGrade();

		Bureaucrat stitch("Stitch", 149);
		std::cout << stitch << std::endl;
		stitch.decrementGrade();

		std::cout << "After increment: " << lilo << std::endl;
		std::cout << "After decrement: " << stitch << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout <<"Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\nTesting Out of bounds" << std::endl;
	std::cout << "----------------------------" << std::endl;

	try
	{
		Bureaucrat lilo("Lilo", 1);
		std::cout << lilo << std::endl;
		std::cout << "Lets increase Lilos grade..." << std::endl;
		lilo.incrementGrade();
		std::cout << "After increment: " << lilo << std::endl; //should not print
	}
	catch (std::exception& e)
	{
		std::cout <<"Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat stitch("Stitch", 150);
		std::cout << stitch << std::endl;
		std::cout << "Lets decrease Stitchs grade..." << std::endl;
		stitch.decrementGrade();
		std::cout << "After decrement: " << stitch << std::endl; // should throw
	}
	catch (std::exception& e)
	{
		std::cout <<"Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nTesting Copy Constructr" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Bureaucrat stitch("Stitch", 42);
	Bureaucrat lilo(stitch); //copy construct lilo from stitch
	std::cout << stitch << std::endl;
	std::cout << "Lilo (copy of Stitch): " << lilo << std::endl;

	std::cout << "\nTesting Assignment operator" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Bureaucrat maui("Maui", 140);
	Bureaucrat moana("Moana", 3);
	maui = moana; //assign lilo to stich
	std::cout << "Maui after assignment from Moana: " << maui << std::endl;
}
