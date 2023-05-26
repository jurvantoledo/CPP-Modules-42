#include "../include/Array.hpp"
#define MAX_VAL 20

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << std::endl;
//         std::cout << "First Index out of bounds: " << std::endl;
//         std::cerr << e.what() << '\n';
//         std::cout << std::endl;
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << std::endl;
//         std::cout << "Second Index out of bounds: " << std::endl;
//         std::cerr << e.what() << '\n';
//         std::cout << std::endl;
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//         std::cout << numbers[i] << ",";
//     }
//     std::cout << std::endl;
//     delete [] mirror;//
//     return 0;
// }

int main()
{
    std::cout << std::endl;
    std::cout << "-------------------- TEST 1 ---------------------" << std::endl;
    try
    {
        Array<int> numbers(MAX_VAL);
        numbers[MAX_VAL] = 10;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "-------------------- TEST 2 ---------------------" << std::endl;
    try
    {
        Array<int> numbers(MAX_VAL);
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = i;
            std::cout << numbers[i] << ",";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "-------------------- TEST 3 ---------------------" << std::endl;
    try
    {
        Array<int> numbers(MAX_VAL);
        Array<int> copy(numbers);
        copy[12] = 666;
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            std::cout << numbers[i] << ",";
        }
        std::cout << std::endl;
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            std::cout << copy[i] << ",";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "-------------------- Check Array Sizes ---------------------" << std::endl;
    std::cout << std::endl;

	std::cout << "size: " << Array<char>(0).size() << std::endl;
	std::cout << "size: " << Array<long>(20).size() << std::endl;
	std::cout << "size: " << Array<void*>(666).size() << std::endl;
    std::cout << std::endl;
    return 0;
}