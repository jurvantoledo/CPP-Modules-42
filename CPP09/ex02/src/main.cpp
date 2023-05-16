#include "../include/PmergeMe.hpp"

int	main(int argc, char *argv[])
{
    std::vector<int> vec;
	std::deque<int> deck;
	unsigned int validated;
	unsigned long long diff;
	timeval start, end;
	PmergeMe pmerge;
	PmergeMe pmergeDeque;

	if (argc < 2)
	{
		std::cout << "Are you dumb? Use more arguments!" << std::endl;
		return (0);
	}

	gettimeofday(&start, NULL);
	try
	{
		validated = pmerge.validate(argc - 1, argv);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: ";
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}

	pmerge.fillVector(vec, argv);
	pmerge.fillDeque(deck, argv);
	std::cout << "Given array is: " << std::endl;
	std::cout << "Vector: "; 
	pmerge.printVectorArray(vec);
	std::cout << "Deque: ";
	pmergeDeque.printDequeArray(deck);	

	pmerge.mergeSort(vec, 0, vec.size() - 1);
	pmergeDeque.mergeSortDeque(deck, 0, deck.size() - 1);

	std::cout << "\nSorted array is" << std::endl;
	std::cout << "Vector: "; 
	pmerge.printVectorArray(vec);
	std::cout << "Deque: ";
	pmergeDeque.printDequeArray(deck);	
	gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << validated << " arguments validated in " << diff << " μs" << std::endl;
	return (0);
}