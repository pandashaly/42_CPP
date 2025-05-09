/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:29:30 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 15:48:45 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void	printIdeas(const Animal* animal, const std::string& petname)
{
	std::cout << std::endl;
	std::cout << animal->getType() << " '" << petname << "' has an idea:" << std::endl;

	const Brain* brain = NULL;

	if (const Dog* dog = dynamic_cast<const Dog*>(animal))
		brain = dog->getBrain();
	else if (const Cat* cat = dynamic_cast<const Cat*>(animal))
		brain = cat->getBrain();

	if (!brain)
	{
		std::cout << "(No brain found 🧠)" << std::endl;
		return;
	}

	for (int i = 0; i < BRAINCAP; i++)
	{
		std::string idea = brain->getIdea(i);
		if (idea.empty())
			break;
		std::cout << "- " << idea << std::endl;
	}
}

int main()
{
	{
		std::cout << "From PDF" << std::endl;
		const Animal* k = new Animal(); //testing if the class can be instatiated and is not abstract
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << k->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		k->makeSound();
		j->makeSound();
		i->makeSound(); //will meow

		delete k;
		delete j;
		delete i;
		std::cout << "===============================" << std::endl;
	}

	std::cout << "\033[36m" << "[ Deep Copy Test - From Subject ]" << "\033[0m" << std::endl;

	Dog basic;
	basic.getBrain()->addIdea("I like bones.", 0);

	{
		Dog tmp = basic;  // copy constructor is called here
		tmp.getBrain()->addIdea("I hate baths.", 1);
		std::cout << "TMP ideas:" << std::endl;
		printIdeas(&tmp, "TmpDog");
	} // tmp is destroyed here

	std::cout << "BASIC ideas (should not include tmp's idea):" << std::endl;
	printIdeas(&basic, "BasicDog");
	
	{
		std::cout << "\033[33m" << "Brain Testing - Looking for Ideas and my last 2 braincells"<< "\033[0m" << std::endl;

		Dog* schatzi = new Dog();
		Dog* ranger = new Dog();
		Cat* mochi = new Cat();

		schatzi->getBrain()->addIdea("I want treats.", 0);
		mochi->getBrain()->addIdea("My human is my servant.", 0);
		*ranger = *schatzi;
		ranger->getBrain()->addIdea("BALL. I want to fetch.", 0);
		Dog* calypso = new Dog(*schatzi);
		calypso->getBrain()->addIdea("I want to dig a hole in th- SQUIRREL!", 0);

		//printing them will allow us to verify independence(deep copy)
		printIdeas(schatzi, "Schatzi");
		printIdeas(ranger, "Ranger");
		printIdeas(calypso, "Calypso");
		printIdeas(mochi, "Mochi");
		std::cout << std::endl;

		delete schatzi;
		delete ranger;
		delete mochi;
		delete calypso;
	}
	return 0;
}

