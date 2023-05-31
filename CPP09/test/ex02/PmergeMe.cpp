#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &c)
{
	*this = c;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator = (const PmergeMe &c)
{
	this->_vec = c._vec;
	this->_list = c._list;
	return (*this);
}

unsigned int PmergeMe::validate(int size, char *argv[])
{
	std::vector<int>	unique_check;

	for (int x = 0; x < size; x++)
	{
		std::string arg(argv[x + 1]);
		for (unsigned long y = 0; y < arg.size(); y++)
			if (arg[y] < '0' || arg[y] > '9')
				throw std::runtime_error("invalid character");
		if (atoi(arg.c_str()) < 0)
			throw std::runtime_error("int is less than 0");
		unique_check.push_back(atoi(arg.c_str()));
	}
	std::sort(unique_check.begin(), unique_check.end());
	for (unsigned long x = 0; x < unique_check.size() - 1; x++)
		if (unique_check[x] == unique_check[x + 1])
			throw std::runtime_error(std::string("duplicate number found: ") + std::to_string(unique_check[x]));
	return unique_check.size();
}

void PmergeMe::loadVec(int size, char *argv[])
{
	for (int x = 0; x < size; x++)
		this->_vec.push_back(atoi(argv[x + 1]));
};

void PmergeMe::loadList(int size, char *argv[])
{
	for (int x = 0; x < size; x++)
		this->_list.push_back(atoi(argv[x + 1]));
};

void PmergeMe::insertionSortVec(std::vector<int>& A, int p, int q)
{
    for (int i = p; i < q; i++)
	{
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tempVal)
		{
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
}

void PmergeMe::mergeVec(std::vector<int>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> LA(n1), RA(n2);
    for (int i = 0; i < n1; i++)
        LA[i] = A[p + i];
    for (int i = 0; i < n2; i++)
        RA[i] = A[q + 1 + i];
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i <= r; i++)
	{
        if (RIDX == n2)
		{
            A[i] = LA[LIDX];
            LIDX++;
        }
		else if (LIDX == n1)
		{
            A[i] = RA[RIDX];
            RIDX++;
        }
		else if (RA[RIDX] > LA[LIDX])
		{
            A[i] = LA[LIDX];
            LIDX++;
        }
		else
		{
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

void PmergeMe::mergeInsertVec(std::vector<int>& A, int p, int r)
{
	int K = 5;

    if (r - p > K)
	{
        int q = (p + r) / 2;
        mergeInsertVec(A, p, q);
        mergeInsertVec(A, q + 1, r);
        mergeVec(A, p, q, r);
    }
	else
        insertionSortVec(A, p, r);
}

void PmergeMe::insertionSortList(std::list<int>& A, int p, int q)
{
    for (int i = p; i < q; i++)
	{
        int tempVal = *std::next(A.begin(), i + 1);
        int j = i + 1;
        while (j > p && *std::next(A.begin(), j - 1) > tempVal)
		{
            *std::next(A.begin(), j) = *std::next(A.begin(), j - 1);
            j--;
        }
        *std::next(A.begin(), j) = tempVal;
    }
}

void PmergeMe::mergeList(std::list<int>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    std::list<int> LA, RA;
    for (int i = 0; i < n1; i++)
        LA.push_back(*std::next(A.begin(), p + i));
    for (int i = 0; i < n2; i++)
        RA.push_back(*std::next(A.begin(), q + 1 + i));
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i <= r; i++)
	{
        if (RIDX == n2)
		{
            *std::next(A.begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        }
		else if (LIDX == n1)
		{
            *std::next(A.begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        }
		else if (RA.front() > LA.front())
		{
            *std::next(A.begin(), i) = LA.front();
            LA.pop_front();
            LIDX++;
        }
		else
		{
            *std::next(A.begin(), i) = RA.front();
            RA.pop_front();
            RIDX++;
        }
    }
}

void PmergeMe::mergeInsertList(std::list<int>& A, int p, int r)
{
	int K = 5;

    if (r - p > K)
	{
        int q = (p + r) / 2;
        mergeInsertList(A, p, q);
        mergeInsertList(A, q + 1, r);
        mergeList(A, p, q, r);
    }
	else
        insertionSortList(A, p, r);
}

void PmergeMe::doVecSort()
{
	this->mergeInsertVec(this->_vec, 0, this->_vec.size() - 1);
}

void PmergeMe::doListSort()
{
	this->mergeInsertList(this->_list, 0, this->_list.size() - 1);
}

bool PmergeMe::areSorted()
{
	for (unsigned long x = 0; x < this->_vec.size() - 1; x++)
		if (this->_vec[x] >= this->_vec[x + 1])
			return (false);
	std::list<int>::iterator it = this->_list.begin();
	while (it != --this->_list.end())
		if (*it >= *++it)
			return (false);
	return (true);
}
