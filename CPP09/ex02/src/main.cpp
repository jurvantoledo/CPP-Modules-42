#include "../include/PmergeMe.hpp"

void	printArray(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}

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
	printArray(vec);
	return (0);
}