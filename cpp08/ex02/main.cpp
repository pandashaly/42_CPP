/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:54:10 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/10 13:05:13 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	//subject main
	MutantStack<int> mutant;
	mutant.push(5);
	mutant.push(17);

	std::cout << mutant.top() << std::endl;

	mutant.pop();
	std::cout << mutant.size() << std::endl;

	mutant.push(3);
	mutant.push(5);
	mutant.push(737);
	mutant.push(0);

	MutantStack<int>::iter it = mutant.begin();
	MutantStack<int>::iter end = mutant.end();

	++it;
	--it;
	while (it != end)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> normalStack(mutant);
	std::cout << "-------------------------" << std::endl;

	//my extra tests
	//compare with list
	std::list<int> mutantTwin;
	mutantTwin.push_back(5);
	mutantTwin.push_back(17);

	std::cout << mutantTwin.back() << std::endl;
	mutantTwin.pop_back();
	std::cout << mutantTwin.size() << std::endl;

	mutantTwin.push_back(3);
	mutantTwin.push_back(5);
	mutantTwin.push_back(737);
	mutantTwin.push_back(0);

	std::list<int>::iterator listIt = mutantTwin.begin();
	std::list<int>::iterator listEnd = mutantTwin.end();

	++listIt;
	--listIt;
	while (listIt != listEnd)
	{
		std::cout << *listIt << std::endl;
		++listIt;
	}

	return 0;
}
