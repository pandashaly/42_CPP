/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:29:30 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 13:18:07 by ssottori         ###   ########.fr       */
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

	const Brain* brain = animal->getBrain();
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
		//const Animal* j = new Dog();
		const Animal* i = new Cat();

		//std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will meow
		//j->makeSound();

		//delete j;
		delete i;
		std::cout << "===============================" << std::endl;
	}
	
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

