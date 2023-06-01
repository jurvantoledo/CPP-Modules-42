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
		std::cout << "More arguments needed!" << std::endl;
		return (0);
	}

	// Validating
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
	gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "-------------------VALIDATING-----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << validated << " arguments validated in " << diff << " μs" << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	

	// Pushing numbers in vector
	std::cout << "-------------------ADD TO VECTOR--------------------" << std::endl;
	std::cout << std::endl;
	gettimeofday(&start, NULL);
	pmerge.fillVector(vec, argv);
	gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "pushed all numbers to vector  in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	std::cout << "-------------------GIVEN ARRAY----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Given array is: ";
	pmerge.printVectorArray(vec);
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	// Merge sort vector
	std::cout << "-------------------MERGE SORT VECTOR-----------------" << std::endl;
	std::cout << std::endl;
    gettimeofday(&start, NULL);
	pmerge.mergeSort(vec, 0, vec.size() - 1);
	gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "sorted vector                 in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;
	pmerge.printVectorArray(vec);
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	
	//  Pushing numbers in vector
	std::cout << "-------------------ADD TO DECK----------------------" << std::endl;
	std::cout << std::endl;
	gettimeofday(&start, NULL);
	pmerge.fillDeque(deck, argv);
	gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "pushed all numbers to deck  in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	
	// Merge sort deque
	std::cout << "-------------------MERGE SORT DECK-----------------" << std::endl;
	std::cout << std::endl;
    gettimeofday(&start, NULL);
	pmergeDeque.mergeSortDeque(deck, 0, deck.size() - 1);
	gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "sorted deck                 in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;
	pmergeDeque.printDequeArray(deck);	
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	return (0);
}