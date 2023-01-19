#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        std::cout << "Cannot use more than 1 argument" << std::endl;
        return (EXIT_FAILURE);
    }
    
    Harl lol;

    lol.complain(argv[1]);

    return (EXIT_SUCCESS);
}