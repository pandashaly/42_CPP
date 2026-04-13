/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:24:09 by ssottori          #+#    #+#             */
/*   Updated: 2025/06/17 22:12:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

//compiler uses tmplate type deduction

// easyfind uses a type T template and the stl library find algorithm 
// to traverse different data containers such as:
//  vector array, lists and double ended queues to find the iterator

int main()
{
	std::cout << "---- testing vector ----- "<< std::endl;
	std::vector<int> vec; 
	vec.push_back(10); //dynamic array
	vec.push_back(20);
	vec.push_back(30);

	//std::cout << "---- Container -----"<< std::endl;
	for (std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "---- ----- -----"<< std::endl;

	//found
	try {
		std::vector<int>::const_iterator it = easyfind(vec, 20);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: "<< e.what() << std::endl;
	}
	//not found
	try {
		std::vector<int>::const_iterator it = easyfind(vec, 13);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
//-----
	std::cout << std::endl;
	std::cout << "---- testing list -----"<< std::endl;
	std::list<int> lst; //2linkedlist
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);

	//std::cout << "---- Container -----"<< std::endl;
	for (std::list<int>::const_iterator iter = lst.begin(); iter != lst.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "---- ----- -----"<< std::endl;

	//found
	try {
		std::list<int>::const_iterator it = easyfind(lst, 25); // returns an iterator(a ptr) to the element 25
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	//not found
	try {
		std::list<int>::const_iterator it = easyfind(lst, 100);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
//-----
	std::cout << std::endl;
	std::cout << "---- testing queue -----"<< std::endl;
	std::deque<int> que; //double ended queue
	que.push_back(5);
	que.push_back(35);
	que.push_back(25);

	for (std::deque<int>::const_iterator iter = que.begin(); iter != que.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "---- ----- -----"<< std::endl;

	//found
	try {
		std::deque<int>::const_iterator it = easyfind(que, 35); // returns an iterator(a ptr) to the element 35
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	//not found
	try {
		std::deque<int>::const_iterator it = easyfind(que, 22);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

// std::vector - whiteboard
// std::list - treasure hunt
// std::deque - train
