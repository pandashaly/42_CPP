/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:33 by ssottori          #+#    #+#             */
/*   Updated: 2025/04/13 15:04:42 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;

};

#endif