#include "../include/Array.hpp"
#define MAX_VAL 50

int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        std::cout << std::endl;
        std::cout << "-------------------- TEST 1 ---------------------" << std::endl;
        numbers[2] = 0;
        std::cout << numbers[2] << std::endl;
    }
    catch(const Array<int>::IndexOutOfBoundsException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl;
        std::cout << "-------------------- TEST 2 ---------------------" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const Array<int>::IndexOutOfBoundsException& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    std::cout << "-------------------- TEST 3 ---------------------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();

        std::cout << numbers[i] << std::endl;
    }
    delete [] mirror;
    return 0;
}