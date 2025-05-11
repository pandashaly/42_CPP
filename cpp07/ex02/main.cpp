/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:02:34 by ssottori          #+#    #+#             */
/*   Updated: 2025/05/11 14:10:39 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void printArr(const Array<T>& arr, const std::string& type)
{
	std::cout << type << std::endl; //type of array
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << "[" << i << "] = " << arr[i] << std::endl;
} //we are printing the index of the array and the value


int main()
{
	std::cout << std::endl;
	std::cout << "------- int arr 5 --------" << std::endl;
	Array<int> intArr(5);
	for (unsigned int i = 0; i < intArr.size(); ++i)
		intArr[i] = i * 1;
	printArr(intArr, "intArray:");
	//=================================
	std::cout << std::endl;
	std::cout << "------- OOB test --------" << std::endl;
	try{
		std::cout << intArr[4] << std::endl; //should work
		std::cout << intArr[10] << std::endl;  //is oob should throw
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	//==================================
	std::cout << std::endl;
	std::cout << "------- copy constructor --------";
	Array<int> copyArr(intArr);
	std::cout << "\ncopyArray contents (after copy):" << std::endl;
	for (unsigned int i = 0; i < copyArr.size(); ++i)
		std::cout << "copyArray[" << i << "] = " << copyArr[i] << std::endl;

	//deep copy test
	copyArr[0] = 42; //we are moifying coppyarr to 42
	std::cout << "\nafter modifying:" << std::endl;
	std::cout << "intArray[0] = " << intArr[0] << std::endl; //intArr should not be affected because its a deep copy
	std::cout << "copyArray[0] = " << copyArr[0] << std::endl;

	std::cout << std::endl;
	std::cout << "------- str array test --------" << std::endl;
	
	Array<std::string> strArr(3);
	strArr[0] = "Hello World!";
	strArr[1] = "This is cpp07";
	strArr[2] = "We are learning about templates and iterating through an array.";
	printArr(strArr, "strArrat:");
	

	return 0;
}
