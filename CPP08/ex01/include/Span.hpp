#ifndef SPAN_H

#define SPAN_H
#include <iostream>
#include <vector>

class Span
{
    private:
        size_t _max;
        std::vector<int> _numbers;

    public:
        Span(size_t amount);
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        ~Span();

        void addNumber(int val);
        int shortestSpan();
        int longestSpan();
    
    private:
        class ArrayOverflow: std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Overflow max size of array");
                }
        };

        class NotEnoughNumbers: std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Not enough numbers");
                }
        };
};

#endif