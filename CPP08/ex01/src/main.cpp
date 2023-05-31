#include "../include/Span.hpp"

int main()
{

    std::cout << std::endl;
    std::cout << "----------- TEST 1 -----------" << std::endl;
    try
    {
        Span s1 = Span(5);
        s1.addNumber(6);
        s1.addNumber(3);
        s1.addNumber(17);
        s1.addNumber(9);
        s1.addNumber(11);

        std::cout << "Shortes span: " << s1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s1.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "----------- TEST 2 -----------" << std::endl;
    try
    {
        Span s1 = Span(10);
        s1.fillSpan(10);

        std::cout << "Shortes span: " << s1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s1.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "----------- TEST 3 -----------" << std::endl;
    try
    {
        Span s1 = Span(5);
        s1.fillSpan(6);

        std::cout << "Shortes span: " << s1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s1.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;


    std::cout << std::endl;
    std::cout << "----------- TEST 4 -----------" << std::endl;
    try
    {
        Span s1 = Span(1);
        s1.fillSpan(1);

        std::cout << "Shortes span: " << s1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s1.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    return (0);
}
