#include "../include/whatever.hpp"

int main()
{
    int result1 = swap<int>(2, 3);
    std::cout << "The first result: " << result1 << std::endl;

    int result2 = min<int>(3, 2);
    std::cout << "The second result: " << result2 << std::endl;

    int result3 = max<int>(3, 2);
    std::cout << "The third result: " << result3 << std::endl;
    return (0);
}