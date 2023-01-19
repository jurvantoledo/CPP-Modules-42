#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "This is an INFO message" << std::endl;
}

void Harl::warning()
{
    std::cout << "This is an WARNING message" << std::endl;

}

void Harl::error()
{
    std::cout << "This is an ERROR message" << std::endl;
}

void Harl::complain(std::string level)
{
    // Array met strings
    std::string levelArr[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };

    // Pointer function met alle funties
    // Maakt een pointer functie aan en in die pointer functie gooi ik andere functies.
	typedef void(Harl::*ptrToMemFunc[])();
	ptrToMemFunc func = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
    // loop om langs alle levels te gaan
    int i = 0;
    while (i < 4)
    {
        if (level == levelArr[i])
        {
            (this->*func[i])();
            return ;
        }
        i++;
    }
    std::cout << "Not able to complain" << std::endl;
    return ;
}