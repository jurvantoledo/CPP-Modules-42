#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

const char* PmergeMe::DuplicateNumberException::what(void) const throw()
{
    return "Duplicate number found!";
}

const char* PmergeMe::NotANumberException::what(void) const throw()
{
    return "One of the values is not a number!";
}

const char* PmergeMe::NotAPositiveNumberException::what(void) const throw()
{
    return "Value is not a positive number!";
}

void	PmergeMe::printVectorArray(std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

void	PmergeMe::printDequeArray(std::deque<int> &deque)
{
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << ' ';
	std::cout << std::endl;
}

int PmergeMe::CheckArguments(char *argv)
{
    for (size_t i = 0; argv[i]; i++)
	{
         if (!isdigit(argv[i]))
            return (1);
	}
    return (0);
}

unsigned int    PmergeMe::validate(int size, char *argv[])
{
    std::vector<int> check;

    for (int i = 0; i < size; i++)
    {
        if (atoi(argv[i + 1]) < 0)
            throw NotAPositiveNumberException();
        if (CheckArguments(argv[i + 1]) == 1)
            throw NotANumberException();
        check.push_back(atoi(argv[i + 1]));
    }
    std::sort(check.begin(), check.end());
    for (unsigned long i = 0; i < check.size() - 1; i++)
    {
        if (check[i] == check[i + 1])
            throw DuplicateNumberException();
    }
    return check.size();
}

void    PmergeMe::merge(std::vector<int> &vec, size_t left, size_t mid, size_t right)
{
    std::vector<int> tempArr(right - left + 1);
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

void    PmergeMe::mergeDeque(std::deque<int> &deck, size_t left, size_t mid, size_t right)
{
    std::deque<int> tempArr(right - left + 1);
    size_t subArrOneIndex = left, subArrTwoIndex = mid + 1, k = 0;

    while (subArrOneIndex <= mid && subArrTwoIndex <= right)
    {
        if (deck[subArrOneIndex] <= deck[subArrTwoIndex])
        {
            tempArr[k] = deck[subArrOneIndex];
            subArrOneIndex++;
        }
        else
        {
            tempArr[k] = deck[subArrTwoIndex];
            subArrTwoIndex++;
        }
        k++;
    }
    
    while (subArrOneIndex <= mid)
    {
        tempArr[k] = deck[subArrOneIndex];
        subArrOneIndex++;
        k++;
    }
    while (subArrTwoIndex <= right)
    {
        tempArr[k] = deck[subArrTwoIndex];
        subArrTwoIndex++;
        k++;
    }

    for (size_t p = 0; p < tempArr.size(); p++)
    {
        deck[left + p] = tempArr[p];
    }
}

void    PmergeMe::mergeSortDeque(std::deque<int> &deck, size_t begin, size_t end)
{
    if (begin >= end)
        return ;

    size_t mid = begin + (end - begin) / 2;
    mergeSortDeque(deck, begin, mid);
    mergeSortDeque(deck, mid + 1, end);
    mergeDeque(deck, begin, mid, end);
}

void    PmergeMe::fillVector(std::vector<int> &vec, char *argv[])
{
    size_t num = 0;
    for (size_t i = 1; argv[i]; i++)
	{
		num = atoi(argv[i]);
		vec.push_back(num);
	}
}

void    PmergeMe::fillDeque(std::deque<int> &deque, char *argv[])
{
    size_t num = 0;
    for (size_t i = 1; argv[i]; i++)
	{
		num = atoi(argv[i]);
		deque.push_back(num);
	}
}