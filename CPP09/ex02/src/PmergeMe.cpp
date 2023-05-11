#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}


void    PmergeMe::swap(int& val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void    PmergeMe::sort(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
	{
		size_t min_idx = i;
		// std::cout << "min_idx: " << min_idx << std::endl;
		for (size_t j = i + 1; j < vec.size(); j++)
		{
			// std::cout << "J: " << j << std::endl;
			if (vec[j] < vec[min_idx])
			{
				min_idx = j;
				// std::cout << "min_idx in if statement: " << min_idx << std::endl;
			}
		}
		swap(vec[i], vec[min_idx]);
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}