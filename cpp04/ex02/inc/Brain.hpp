/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:45:27 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 00:33:23 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# ifndef BRAINCAP
#  define BRAINCAP 100
# endif

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
		void addIdea(std::string idea, int i);
		std::string getIdea(int id) const;
		void removeIdea(int id);

	private:
	std::string ideas[BRAINCAP]; //we are in memory leak territory now :O
};

#endif