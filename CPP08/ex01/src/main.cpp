#include "../include/Span.hpp"

int main()
{
    Span s1 = Span(5);
    s1.addNumber(5);
    s1.addNumber(2);
    s1.addNumber(3);
    s1.addNumber(4);
    s1.addNumber(1);
    std::cout << "Shortes span: " << s1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << s1.longestSpan() << std::endl;    
    return (0);
}