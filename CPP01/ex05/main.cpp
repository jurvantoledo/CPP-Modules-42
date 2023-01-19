#include "Harl.hpp"

int main()
{
    Harl lol;

    std::cout << std::endl;
    std::cout << "DEBUG MESSAGE:" << std::endl;
    lol.complain("DEBUG");
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "WARNING MESSAGE:" << std::endl;
    lol.complain("WARNING");
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "INFO MESSAGE:" << std::endl;
    lol.complain("INFO");
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "ERROR MESSAGE:" << std::endl;
    lol.complain("ERROR");
    std::cout << std::endl;
    return 0;
}