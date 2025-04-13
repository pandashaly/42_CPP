/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:35:14 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 21:04:55 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat();

		void makeSound() const;

};

#endif