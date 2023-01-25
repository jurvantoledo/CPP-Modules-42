#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        ClapTrap claptrap;

        std::cout << "<< Claptrap attacks until he has no energy left >>" << std::endl;
        int i = 0;
        while (i < 10)
        {
            claptrap.attack("jan");
            i++;
        }
        std::cout << std::endl;
        std::cout << "<< ClapTrap gert tries to repair himself with no energy >>" << std::endl;
        claptrap.beRepaired(10);
        std::cout << std::endl;
    }
    {
        std::cout << std::endl;
        ScavTrap scavtrap;
        std::cout << "<< ScavTrap attacks and goes in guard mode >>" << std::endl;
        scavtrap.attack("Bert");
        scavtrap.guardGate();
        std::cout << std::endl;
    }
    return (0);
}