/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:29:30 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 14:51:28 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	{
		std::cout << "\033[33m" << "From PDF\n"<< "\033[0m";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	
	{
		std::cout << "\033[33m" << "\nFrom PDF but exchanged with WrongAnimal and WrongCat\n"<< "\033[0m";
		const WrongAnimal* animal = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();

		std::cout << "animal type: " << animal->getType() << std::endl;
		std::cout << "cat type: " << cat->getType() << std::endl;
		
		std::cout << "Panda says: ";
		animal->makeSound(); //will output the wrongAnimal sound
		std::cout << "cat says: ";
		cat->makeSound(); //will still output wronganimal sound unless virtual is being used

		delete animal;
		delete cat;
	}
	return 0;
}

