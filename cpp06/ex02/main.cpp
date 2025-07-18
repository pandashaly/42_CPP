/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:47:39 by ssottori          #+#    #+#             */
/*   Updated: 2025/07/18 18:59:15 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
	int random_num = std::rand() % 3;
	// std::cout << "num = " << random_num << std::endl;
	if(random_num == 0)
		return (new A());
	else if(random_num == 1)
		return (new B());
	else
		return (new C());
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer is an instance of class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer is an instance of class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer is an instance of class C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference is an instance of class A" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference is an instance of class B" << std::endl;
		return ;
	}
	catch(...) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference is an instance of class C" << std::endl;
		return ;
	}
	catch(...) { std::cout << "Unknown type." << std::endl;;}
}

int main() 
{
	std::srand(std::time(0));

	Base *b = generate();
	identify(b);
	identify(*b);
	
	delete b;
	return 0;
}
