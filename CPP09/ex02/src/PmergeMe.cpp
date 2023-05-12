#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

const char* PmergeMe::NotANumberException::what(void) const throw()
{
    return "One of the values is not a number";
}

int PmergeMe::CheckArguments(char *argv[])
{
    for (size_t i = 1; argv[i]; i++)
	{
        for (size_t j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                return (1);
        }
	}
    return (0);
}

void    PmergeMe::merge(std::vector<int> &vec, size_t left, size_t mid, size_t right)
{
    std::vector<int> tempArr(right - left + 1);

    // vec[left ... mid] & vec[mid + 1 ... right] mergen
    size_t subArrOneIndex = left, subArrTwoIndex = mid + 1, k = 0;

    while (subArrOneIndex <= mid && subArrTwoIndex <= right)
    {
        if (vec[subArrOneIndex] <= vec[subArrTwoIndex])
        {
            tempArr[k] = vec[subArrOneIndex];
            subArrOneIndex++;
        }
        else
        {
            tempArr[k] = vec[subArrTwoIndex];
            subArrTwoIndex++;
        }
        k++;
    }
    
    while (subArrOneIndex <= mid)
    {
        tempArr[k] = vec[subArrOneIndex];
        subArrOneIndex++;
        k++;
    }
    while (subArrTwoIndex <= right)
    {
        tempArr[k] = vec[subArrTwoIndex];
        subArrTwoIndex++;
        k++;
    }

    for (size_t p = 0; p < tempArr.size(); p++)
    {
        vec[left + p] = tempArr[p];
    }
}

void    PmergeMe::mergeSort(std::vector<int> &vec, size_t begin, size_t end)
{
    if (begin >= end)
        return ;

    size_t mid = begin + (end - begin) / 2;
    mergeSort(vec, begin, mid);
    mergeSort(vec, mid + 1, end);
    merge(vec, begin, mid, end);
}

void    PmergeMe::fillArr(std::vector<int> &vec, char *argv[])
{
    size_t num = 0;
    for (size_t i = 1; argv[i]; i++)
	{
        if (CheckArguments(argv) == 1)
            throw NotANumberException();
		num = atoi(argv[i]);
		vec.push_back(num);
	}
}
