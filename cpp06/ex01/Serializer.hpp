/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:35:35 by ssottori          #+#    #+#             */
/*   Updated: 2025/07/18 18:45:26 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <stdint.h>
# include <iostream>

struct Data
{
    int id;
	std::string name;
	std::string sername;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
