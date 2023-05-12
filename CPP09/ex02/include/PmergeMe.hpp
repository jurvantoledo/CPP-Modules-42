#ifndef PMERGE_H
#define PMERGE_H
#include <iostream>
#include <vector>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		~PmergeMe();

		void 	mergeSort(std::vector<int> &vec, size_t begin, size_t end);
		void 	merge(std::vector<int> &vec, size_t left, size_t mid, size_t right);
		int		CheckArguments(char *argv[]);
		void	fillArr(std::vector<int> &vec, char *argv[]);

		class NotANumberException : public std::exception {
			const char* what() const throw();
		};
};

#endif