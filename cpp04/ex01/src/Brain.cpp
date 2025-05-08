/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:50:13 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 13:26:41 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//OCF
Brain::Brain(void)
{
	std::cout << "Brain created! Animal has gained conciousness" << std::endl;
}

Brain::Brain(const Brain & other)
{
	int i = 0;

	std::cout << "Brain copied!" << std::endl;
	while (i < BRAINCAP)
	{
		this->ideas[i] = other.getIdea(i);
		i++;
	}
}

Brain::~Brain(void) 
{
	std::cout << "Brain-dead!" << std::endl;
}

Brain & Brain::operator = (const Brain & other)
{
	if (this != &other)
	{
		for (int i = 0; i < BRAINCAP; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

void Brain::addIdea(std::string idea, int i)
{
	//int i = 0;

	while (i < BRAINCAP && ideas[i] != "")
		i++;
	if (i < BRAINCAP)
		ideas[i] = idea;
	else
		std::cout << "This animal can't have more new ideas until forgets something" << std::endl;
}

std::string Brain::getIdea(int id) const
{
	if (id >= 0 && id < BRAINCAP)
		return(this->ideas[id]);
	return ("");
}

void Brain::removeIdea(int id)
{
	if (id > 0 && id < BRAINCAP)
		this->ideas[id] = "";
}