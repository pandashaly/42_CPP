/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:29:46 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/08 15:17:43 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOGCAT_HPP
# define DOGCAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		Brain* getBrain() const;
		void makeSound() const;
};

class Cat : public AAnimal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat();

		Brain* getBrain() const;
		void makeSound() const;

};

#endif