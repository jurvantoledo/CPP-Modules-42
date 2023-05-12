#ifndef PMERGE_H
#define PMERGE_H
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		~PmergeMe();

		// Vector merge sort functions
		void 	mergeSort(std::vector<int> &vec, size_t begin, size_t end);
		void 	merge(std::vector<int> &vec, size_t left, size_t mid, size_t right);
		void	fillVector(std::vector<int> &vec, char *argv[]);

		// Deque merge sort functions
		void	mergeSortDeque(std::deque<int> &deck, size_t begin, size_t end);
		void	mergeDeque(std::deque<int> &deck, size_t left, size_t mid, size_t right);
		void	fillDeque(std::deque<int> &deque, char *argv[]);
		
		// Check functions
		void	printVectorArray(std::vector<int> &vec);
		void	printDequeArray(std::deque<int> &deque);
		int		CheckArguments(char *argv[]);

		class NotANumberException : public std::exception {
			const char* what() const throw();
		};

		class NotAPositiveNumberException : public std::exception {
			const char* what() const throw();
		};
};

#endif