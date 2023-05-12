#include "../include/PmergeMe.hpp"

int	main(int argc, char *argv[])
{
    std::vector<int> vec;
	std::deque<int> deck;

	if (argc < 2)
	{
		std::cout << "Are you dumb? Use more arguments!" << std::endl;
		return (0);
	}
	try
	{
		PmergeMe pmerge;
		PmergeMe pmergeDeque;

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
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: ";
		std::cerr << e.what() << '\n';
	}
	return (0);
}