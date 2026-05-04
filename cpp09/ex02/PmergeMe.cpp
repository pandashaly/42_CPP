#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe() {}

bool	PmergeMe::isValidNumber(const std::string &str)
{
	size_t	i;

	i = 0;
	if (str.empty())
		return (false);
	while (i < str.length())
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

void	PmergeMe::parse(char **argv)
{
	int			i;
	long		value;
	std::string	str;

	i = 1;
	while (argv[i])
	{
		str = argv[i];
		if (!isValidNumber(str))
			throw std::runtime_error("Error");
		value = std::strtol(str.c_str(),NULL,10);
		if (value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");
		// if (std::find(_vector.begin(),_vector.end(),static_cast<int>(value)) != _vector.end())
		// 	throw std::runtime_error("Error");
		//this is for handling duplicate numbers
		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
		i++;
	}
	if (_vector.empty())
		throw std::runtime_error("Error");
}

void	PmergeMe::printSequence(const std::string &label,const std::vector<int> &seq)
{
	size_t	i;

	std::cout << label;
	i = 0;
	while (i < seq.size())
	{
		std::cout << seq[i];
		if (i + 1 < seq.size())
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}

int	PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

std::vector<int>	PmergeMe::jacobOrder(int size)
{
	std::vector<int>	order;
	std::vector<int>	used;
	int					jacob;
	int					prev;
	int					value;
	int					i;

	if (size <= 0)
		return (order);
	used.resize(size,0);
	order.push_back(0);
	used[0] = 1;
	i = 3;
	prev = 1;
	while (true)
	{
		jacob = jacobsthal(i);
		if (jacob > size)
			jacob = size;
		value = jacob - 1;
		while (value >= prev)
		{
			if (!used[value])
			{
				order.push_back(value);
				used[value] = 1;
			}
			value--;
		}
		if (jacob == size)
			break;
		prev = jacob;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (!used[i])
			order.push_back(i);
		i++;
	}
	return (order);
}

int	PmergeMe::binarySearchVector(std::vector<int> &chain,int value,int end)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = end;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

int	PmergeMe::binarySearchDeque(std::deque<int> &chain,int value,int end)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = end;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

std::vector<int>	PmergeMe::sortVector(std::vector<int> input)
{
	std::vector< std::pair<int,int> >	pairs;
	std::vector<int>					mainChain;
	std::vector<int>					pend;
	std::vector<int>					order;
	std::vector<int>					partner;
	std::vector<int>					result;
	std::pair<int,int>					current;
	int									straggler;
	bool								hasStraggler;
	size_t								i;
	size_t								j;
	int									pos;
	int									bound;

	if (input.size() <= 1)
		return (input);
	hasStraggler = false;
	straggler = 0;
	i = 0;
	while (i + 1 < input.size())
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i],input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1],input[i]));
		i += 2;
	}
	if (i < input.size())
	{
		hasStraggler = true;
		straggler = input[i];
	}
	i = 0;
	while (i < pairs.size())
	{
		mainChain.push_back(pairs[i].first);
		i++;
	}
	mainChain = sortVector(mainChain);
	if (!pairs.empty())
	{
		i = 0;
		while (i < mainChain.size())
		{
			j = 0;
			while (j < pairs.size())
			{
				if (pairs[j].first == mainChain[i])
				{
					pend.push_back(pairs[j].second);
					partner.push_back(pairs[j].first);
					pairs.erase(pairs.begin() + j);
					break;
				}
				j++;
			}
			i++;
		}
	}
	result = mainChain;
	order = jacobOrder(pend.size());
	i = 0;
	while (i < order.size())
	{
		current = std::make_pair(pend[order[i]],partner[order[i]]);
		bound = 0;
		while (bound < static_cast<int>(result.size()) && result[bound] != current.second)
			bound++;
		pos = binarySearchVector(result,current.first,bound);
		result.insert(result.begin() + pos,current.first);
		i++;
	}
	if (hasStraggler)
	{
		pos = binarySearchVector(result,straggler,result.size());
		result.insert(result.begin() + pos,straggler);
	}
	return (result);
}

std::deque<int>	PmergeMe::sortDeque(std::deque<int> input)
{
	std::deque< std::pair<int,int> >	pairs;
	std::deque<int>					mainChain;
	std::deque<int>					pend;
	std::deque<int>					partner;
	std::deque<int>					result;
	std::vector<int>				order;
	std::pair<int,int>				current;
	int								straggler;
	bool							hasStraggler;
	size_t							i;
	size_t							j;
	int								pos;
	int								bound;

	if (input.size() <= 1)
		return (input);
	hasStraggler = false;
	straggler = 0;
	i = 0;
	while (i + 1 < input.size())
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i],input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1],input[i]));
		i += 2;
	}
	if (i < input.size())
	{
		hasStraggler = true;
		straggler = input[i];
	}
	i = 0;
	while (i < pairs.size())
	{
		mainChain.push_back(pairs[i].first);
		i++;
	}
	mainChain = sortDeque(mainChain);
	if (!pairs.empty())
	{
		i = 0;
		while (i < mainChain.size())
		{
			j = 0;
			while (j < pairs.size())
			{
				if (pairs[j].first == mainChain[i])
				{
					pend.push_back(pairs[j].second);
					partner.push_back(pairs[j].first);
					pairs.erase(pairs.begin() + j);
					break;
				}
				j++;
			}
			i++;
		}
	}
	result = mainChain;
	order = jacobOrder(pend.size());
	i = 0;
	while (i < order.size())
	{
		current = std::make_pair(pend[order[i]],partner[order[i]]);
		bound = 0;
		while (bound < static_cast<int>(result.size()) && result[bound] != current.second)
			bound++;
		pos = binarySearchDeque(result,current.first,bound);
		result.insert(result.begin() + pos,current.first);
		i++;
	}
	if (hasStraggler)
	{
		pos = binarySearchDeque(result,straggler,result.size());
		result.insert(result.begin() + pos,straggler);
	}
	return (result);
}

void	PmergeMe::run()
{
	std::vector<int>	sortedVector;
	std::deque<int>		sortedDeque;
	clock_t				start;
	clock_t				end;
	double				timeVector;
	double				timeDeque;

	printSequence("Before: ",_vector);
	start = std::clock();
	sortedVector = sortVector(_vector);
	end = std::clock();
	timeVector = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	start = std::clock();
	sortedDeque = sortDeque(_deque);
	end = std::clock();
	timeDeque = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	printSequence("After: ",sortedVector);
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque : " << timeDeque << " us" << std::endl;
}
