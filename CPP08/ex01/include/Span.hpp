#ifndef SPAN_H

#define SPAN_H
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        size_t _max;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        ~Span();

        void addNumber(int val);
        int shortestSpan();
        int longestSpan();
        void fillSpan(int amount);
    
        class ArrayOverflow : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NotEnoughNumbers : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif