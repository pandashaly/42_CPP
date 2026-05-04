/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:07:06 by ssottori          #+#    #+#             */
/*   Updated: 2026/05/04 19:02:47 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <cstdlib>
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
		int		binarySearchVector(std::vector<int> &chain,int value,int end);
		int		binarySearchDeque(std::deque<int> &chain,int value,int end);
		bool	isValidNumber(const std::string &str);
		void	printSequence(const std::string &label,const std::vector<int> &seq);
};
