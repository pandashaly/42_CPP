/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:23:47 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 18:12:51 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


//A grade ranges from 1 (highest possible grade) to 150 (lowest possible grade).
int main()
{
	std::cout << "\nTesting valid form + bureaucrat" << std::endl;
	std::cout << "-------------------------" << std::endl;
	try
	{
		Bureaucrat bond("Bond 007", 1);
		std::cout << bond << std::endl;

		Form ts("TopSecret", 50, 25);
		std::cout << ts << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	// =================================
	std::cout << "\nTesting signing" << std::endl;
	std::cout << "----------------------------" << std::endl;
	
	try //successful signing
	{
		Bureaucrat bond("Bond 007", 1);
		std::cout << bond << std::endl;
		Form ts("TopSecret", 50, 25);
		bond.signForm(ts); //signing with sufficingt grade
		std::cout << ts << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try //unsuccessful signing
	{
		Bureaucrat potus("POTUS", 148);
		std::cout << potus << std::endl;
		Form codes("NuclearCodes", 10, 5);
		potus.signForm(codes); //signing with insufficingt grade
		std::cout << codes << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	//=========================
	std::cout << "\nTesting Out of bounds" << std::endl;
	std::cout << "----------------------------" << std::endl;

	try {
		Form bad1("TooHigh", 0, 100);  // throws
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Form bad2("TooLow", 100, 151);  // throws
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// ============================
	std::cout << "\nTesting Assignment op and copy const" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Form original("Black Ops", 42, 10);
	std::cout << "Original: " << original << std::endl;
	// Copy const
	Form copy(original);
	std::cout << "Copy (via constructor): " << copy << std::endl;

	// assignment op
	Form assigned("Temp", 150, 150); // dummy form
	assigned = original;
	std::cout << "Assigned: " << assigned << std::endl;
}
