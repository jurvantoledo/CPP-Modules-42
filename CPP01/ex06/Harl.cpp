#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout << std::endl;
    std::cout << "[ DEBUG ]:" << std::endl;
    std::cout << "This is a DEBUG message" << std::endl;
}

void Harl::info()
{
    std::cout << std::endl;
    std::cout << "[ INFO ]:" << std::endl;
    std::cout << "This is a INFO message" << std::endl;
}

void Harl::warning()
{
    std::cout << std::endl;
    std::cout << "[ WARNING ]:" << std::endl;
    std::cout << "This is a WARNING message" << std::endl;
}

void Harl::error()
{
    std::cout << std::endl;
    std::cout << "[ ERROR ]:" << std::endl;
    std::cout << "This is a ERROR message" << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levelArr[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };

    typedef void(Harl::*ptrToMemFunc[])();
    ptrToMemFunc func = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    int i;
    i = 0;
    while (i < 4)
    {
        if (levelArr[i] == level)
            break ;
        i++;
    }

    switch (i) {
        case 0:
            (this->*func[0])();
        case 1:
            (this->*func[1])();
        case 2:
            (this->*func[2])();
        case 3:
            (this->*func[3])();
            break;
        default:
            std::cout << "USE DEBUG | INFO | WARNING | ERROR" << std::endl;
            break;
    }
    return ;
}