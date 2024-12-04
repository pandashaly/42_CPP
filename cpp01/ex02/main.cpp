/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:35:37 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/04 15:23:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << std::endl;
    std::cout << "Printing the addresses..." << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Memory address of str: " << &str <<std::endl;
    std::cout << "Memory address held by strPTR: " << strPTR << std::endl;
    std::cout << "Memory address held by strREF: " << &strREF << std::endl <<std::endl;
    std::cout << "=============================================" << std::endl << std::endl;
    std::cout << "Printing the values..." << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value pointed to by strPTR: " << *strPTR << std::endl;
    std::cout << "Value pointed to by strREF: " << strREF << std::endl;
    return (0);
}