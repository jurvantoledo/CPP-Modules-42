#include "../include/Types.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "More arguments needed bitch" << std::endl;
        return (0);
    }
    Types lol(argv[1]);

    lol.ConvertTo();
    lol.DisplayVars();
    return (0);
}