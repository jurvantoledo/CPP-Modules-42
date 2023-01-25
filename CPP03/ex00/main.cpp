#include "ClapTrap.hpp"

int main() 
{
    {
        ClapTrap gert("Gert");
        ClapTrap jan("Jan");

        std::cout << "<< Claptrap gert attacks until he has no energy left >>" << std::endl;
        int i = 0;
        while (i < 11)
        {
            gert.attack("jan");
            jan.takeDamage(1);
            i++;
        }
        std::cout << std::endl;
        std::cout << "<< ClapTrap gert tries to repair himself with no energy >>" << std::endl;
        gert.beRepaired(10);
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << std::endl;
        ClapTrap claptrap;
        std::cout << "<< Claptrap will heal 5hp 3x >>" << std::endl;
        claptrap.beRepaired(5);
        claptrap.beRepaired(5);
        claptrap.beRepaired(5);
    }
    return (0);
}