#include <iomanip>
#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

#include <unistd.h>
int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cerr << "usage: ./PmergeMe <input>" << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe merge;
	unsigned int validated;
	unsigned long long diff;
    timeval start, end;


    gettimeofday(&start, NULL);
	try
	{
		validated = merge.validate(argc - 1, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Parsing error: " << e.what() << std::endl;
		gettimeofday(&end, NULL);
		diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
		std::cout << "failed validating arguments in " << diff << "μs" << std::endl;
		return (EXIT_FAILURE);
	}
    gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << std::setw(6) << validated << " arguments validated    in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;

    gettimeofday(&start, NULL);
	merge.loadVec(argc - 1, argv);
    gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "pushed all numbers to vector  in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;

    gettimeofday(&start, NULL);
	merge.loadList(argc - 1, argv);
    gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "pushed all numbers to list    in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;

    gettimeofday(&start, NULL);
	merge.doVecSort();
    gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "sorted vector                 in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;

    gettimeofday(&start, NULL);
	merge.doListSort();
    gettimeofday(&end, NULL);
	diff = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "sorted list                   in " << std::setfill(' ') << std::setw(9) << diff << " μs" << std::endl;

	std::cout << "sorted                           " << std::setw(9);
	if (merge.areSorted())
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
