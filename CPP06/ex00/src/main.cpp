#include "../include/Types.hpp"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        Types lol;
        lol.getTypes(argv[1]);
        return (EXIT_SUCCESS);
    }

    std::cout << "More arguments needed bitch" << std::endl;
    return (EXIT_SUCCESS);
}