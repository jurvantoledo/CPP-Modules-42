#include "../include/PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	PmergeMe pmerge;
	std::vector<int> vec;
	int	num = 0;

	if (argc < 2)
	{
		std::cout << "Are you dumb? Use more arguments!" << std::endl;
		return (0);
	}

	for (size_t i = 1; argv[i]; i++)
	{
		num = atoi(argv[i]);
		vec.push_back(num);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;

	// for (size_t i = 0; i < vec.size() - 1; i++)
	// {
	// 	if (vec[i] > vec[i + 1])
	// 	{
	// 		pmerge.swap(vec[i], vec[i + 1]);
	// 	}
	// }
	std::cout << "After: ";
	pmerge.sort(vec);
	// for (size_t i = 0; i < vec.size(); i++)
	// {
	// 	size_t min_idx = i;
	// 	for (size_t j = i + 1; j < vec.size(); j++)
	// 	{
	// 		if (vec[j] < vec[min_idx])
	// 		{
	// 			min_idx = j;
	// 		}
	// 	}
	// 	pmerge.swap(vec[i], vec[min_idx]);
	// 	std::cout << vec[i] << ' ';
	// }
	// std::cout << std::endl;
	return (0);
}