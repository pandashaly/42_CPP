#include "PmergeMe.hpp"

// OCF ----
PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe() {}

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
	timeVector = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;
	start = std::clock();
	sortedDeque = sortDeque(_deque);
	end = std::clock();
	timeDeque = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;
	printSequence("After: ",sortedVector);
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << timeVector << " ms" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque : " << timeDeque << " ms" << std::endl;
}

//input ---------
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

//Jacobbbb
// J(n) = J(n-1) + 2*J(n-2)
//0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461...etc
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
	// element 0 always goes in first
	order.push_back(0);
	used[0] = 1;
	i = 3; 	// start at i=3 because jacobsthal(2) == jacobsthal(1) == 1
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

//sorting

std::vector<int>    PmergeMe::sortVector(std::vector<int> input)
{
    return sortContainer(input);
}

std::deque<int>     PmergeMe::sortDeque(std::deque<int> input)
{
	return sortContainer(input);
}
