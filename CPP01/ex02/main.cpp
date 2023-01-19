#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of String: " << &str << std::endl;
    std::cout << "Memory address of Pointer: " << stringPTR << std::endl;
    std::cout << "Memory address of Reference: " << &stringREF << std::endl;

    std::cout << "Value of String: " << str << std::endl;
    std::cout << "Value of Pointer: " << *stringPTR << std::endl;
    std::cout << "Value of Reference: " << stringREF << std::endl;
    return 0;
}