#ifndef PMERGEME_H
#define PMERGEME_H

#include <string>
#include <exception>
#include <algorithm>
#include <sstream>
#include <vector>
#include <list>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &c);
    PmergeMe & operator = (const PmergeMe &c);

	unsigned int	validate(int size, char *argv[]);
	void			loadVec(int size, char *argv[]);
	void			loadList(int size, char *argv[]);

	bool			areSorted();

	void			doVecSort();
	void			doListSort();
private:
	void			insertionSortVec(std::vector<int>& A, int p, int q);
	void			mergeVec(std::vector<int>& A, int p, int q, int r);
	void			mergeInsertVec(std::vector<int>& A, int p, int r);

	void			insertionSortList(std::list<int>& A, int p, int q);
	void			mergeList(std::list<int>& A, int p, int q, int r);
	void			mergeInsertList(std::list<int>& A, int p, int r);

	std::vector<int>	_vec;
	std::list<int>		_list;
};

#endif