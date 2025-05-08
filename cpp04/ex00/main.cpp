/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:29:30 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 14:06:32 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\033[33m" << "From PDF\n"<< "\033[0m";
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound(); //dog sound

		//if it wasnt virtual it would output Animal noises

		delete j;
		delete i;
	}
	
	{
		std::cout << "\033[33m" << "\nFrom PDF but exchanged with WrongAnimal and WrongCat\n"<< "\033[0m";
		const WrongAnimal* animal = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		const WrongCat* wrongcat = new WrongCat();

		std::cout << "Animal type: " << animal->getType() << std::endl;
		std::cout << "Cat type: " << cat->getType() << std::endl;
		std::cout << "Wrong Cat type: " << wrongcat->getType() << std::endl;
		
		std::cout << "Panda says: ";
		animal->makeSound(); //will output the wrongAnimal sound
		std::cout << "Cat says: ";
		cat->makeSound(); //will still output wronganimal sound because we used wronganimal
		std::cout << "Wrong Cat says: ";
		wrongcat->makeSound(); //will still output wrongcat


		delete animal;
		delete cat;
		delete wrongcat;
	}
	return 0;
}

