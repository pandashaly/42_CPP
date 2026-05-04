/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:07:06 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 21:35:32 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <ctime>
# include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

	public:
		PmergeMe();
		~PmergeMe();
		void	parse(char **argv);
		void	run();

	private:
		std::vector<int>	sortVector(std::vector<int> input);
		std::deque<int>		sortDeque(std::deque<int> input);
		std::vector<int>	jacobOrder(int size);
		int					jacobsthal(int n);
		// int		binarySearchVector(std::vector<int> &chain,int value,int end);
		// int		binarySearchDeque(std::deque<int> &chain,int value,int end);
		bool	isValidNumber(const std::string &str);
		void	printSequence(const std::string &label,const std::vector<int> &seq);
		
		template <typename Container>
		Container	sortContainer(Container input);

		template <typename Container>
		int		binarySearch(const Container& container, int val, int bound);
};

//----------------------
//Template implementations
template <typename Container>
Container	PmergeMe::sortContainer(Container input)
{
	std::vector<std::pair<int, int> >	pairs;
	Container							mainChain;
	Container							lilBro; //smaller of each pair
	Container							bigBro; //tracks which mainchain element each lilBro belongs to
	Container							result;
	std::vector<int>					order;
	std::pair<int, int>					current;
	int									loner;
	bool								hasLoner;
	size_t								i;
	size_t								j;
	int									pos;
	int									boundary;

	if (input.size() <= 1)
		return (input);
	hasLoner = false;
	loner = 0;
	i = 0;
	//creating pairs with biggest elements
	while (i + 1 < input.size())
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
		i += 2;
	}
	//odd number of elemnts?
	if (i < input.size()) 
	{
		hasLoner = true;
		loner = input[i]; //remember loner for later - we input loners last
	}
	i = 0;
	while (i < pairs.size())
	{
		mainChain.push_back(pairs[i].first);
		i++;
	}
	//sort recursivleyyyy until size <= 1
	mainChain = sortContainer(mainChain);
	if (!pairs.empty()) //matching each pair to where its bigger element ended up
	{
		i = 0;
		while (i < mainChain.size())
		{
			j = 0;
			while (j < pairs.size())
			{
				if (pairs[j].first == mainChain[i])
				{
					lilBro.push_back(pairs[j].second);
					bigBro.push_back(pairs[j].first);
					pairs.erase(pairs.begin() + j);
					break;
				}
				j++;
			}
			i++;
		}
	}
	// TODO: maybe optimize this later?
	result = mainChain;
	order = jacobOrder(lilBro.size()); // generate jacobsthal insertion order
	i = 0;
	// insert lilBro elements in jacobsthal order
	while (i < order.size())
	{
		current = std::make_pair(lilBro[order[i]], bigBro[order[i]]);
		// boundary = position of its bigBro in result, no point searching past it
		boundary = 0;
		while (boundary < static_cast<int>(result.size()) && result[boundary] != current.second)
			boundary++;
		pos = binarySearch(result, current.first, boundary);
		result.insert(result.begin() + pos, current.first);
		i++;
	}
	if (hasLoner) //Loner goes last
	{
		pos = binarySearch(result, loner, result.size());
		result.insert(result.begin() + pos, loner);
	}
	return (result);
	//DO NOT TOUCH THIIISS!!! IT WORKS
}

// binary search onlyyyyy up to bound not the whole array
template <typename Container>
int	PmergeMe::binarySearch(const Container &container, int val, int limit)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = limit;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		// std::cout << "mid: " << mid << std::endl;
		if (container[mid] < val)
			left = mid + 1;
		else
			right = mid;
	}
	// ??? infinite loop whyyyyy???
	return (left);
}

//should work

