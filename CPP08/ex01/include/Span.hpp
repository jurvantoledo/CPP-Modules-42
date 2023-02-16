#ifndef SPAN_H

#define SPAN_H
#include <iostream>
#include <set>

class Span
{
    private:
        std::multiset<int> _numbers;
        size_t max;

    public:
        Span(size_t amount);
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        ~Span();

        void addNumber(int val);
        size_t shortestSpan();
        size_t longestSpan();
};

#endif