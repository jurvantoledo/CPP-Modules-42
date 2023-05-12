#include "../include/PmergeMe.hpp"

void	printArray(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
    std::vector<int> vec;

	if (argc < 2)
	{
		std::cout << "Are you dumb? Use more arguments!" << std::endl;
		return (0);
	}
	try
	{
		PmergeMe pmerge;
		
		pmerge.fillArr(vec, argv);
		std::cout << "Given array is \n";
		printArray(vec);
	
		pmerge.mergeSort(vec, 0, vec.size() - 1);
	
		std::cout << "\nSorted array is \n";
		printArray(vec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}