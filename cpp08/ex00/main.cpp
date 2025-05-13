/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:24:09 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/13 17:50:36 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "---- testing vector ----- "<< std::endl;
	std::vector<int> vec;
	vec.push_back(10); //dynamic array
	vec.push_back(20);
	vec.push_back(30);

	try {
		std::vector<int>::const_iterator it = easyfind(vec, 20);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---- testing list -----"<< std::endl;
	std::list<int> lst; //2linkedlist
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);

	try {
		std::list<int>::const_iterator it = easyfind(lst, 25); // returns an iterator(a ptr) to the element 25
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---- testing queue -----"<< std::endl;
	std::deque<int> lst; //2linkedlist
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);

	try {
		std::list<int>::const_iterator it = easyfind(lst, 25); // returns an iterator(a ptr) to the element 25
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}