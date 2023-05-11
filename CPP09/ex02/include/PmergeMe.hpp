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

		void	swap(int& val1, int& val2);
		void	sort(std::vector<int> vec);
};

#endif