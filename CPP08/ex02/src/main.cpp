#include "../include/MutantStack.hpp"

int main()
{
    MutantStack<int>    mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << std::endl;
    std::cout << "The top item of array " << mstack.top() << std::endl;
    std::cout << std::endl;
    mstack.pop();

    std::cout << "The size after pop " << mstack.size() << std::endl;
    std::cout << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    return (0);
}