/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:40:55 by ssottori          #+#    #+#             */
/*   Updated: 2025/07/18 19:06:39 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data* data = new Data;
	data->id = 42;
	data->name = "Forty";
	data->sername = "Two";

	std::cout << "Original ptr:    " << data << std::endl;
	std::cout << "Original val:" << std::endl;
	std::cout << "  ID:      " << data->id << std::endl;
	std::cout << "  Name:    " << data->name << std::endl;
	std::cout << "  Sername: " << data->sername << std::endl;

	// Serialize and deserialize the pointer
	uintptr_t raw = Serializer::serialize(data);
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Serialized value:    " << raw << std::endl;
	std::cout << "Deserialized pointer:" << deserialized << std::endl;
	std::cout << "Deserialized values:" << std::endl;
	std::cout << "  ID:      " << deserialized->id << std::endl;
	std::cout << "  Name:    " << deserialized->name << std::endl;
	std::cout << "  Sername: " << deserialized->sername << std::endl;

	// Check pointer identity
	if (deserialized == data)
		std::cout << "YAYYyYY pointers match!" << std::endl;
	else
		std::cout << "OOOoOps pointers do not match!" << std::endl;

	delete data;

	return 0;
}
