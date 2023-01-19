#include "Weapon.hpp"

int main()
{
    {
        std::string const weaponType;
        Weapon club = Weapon("crude spiked club");

        club.setType("some other type of club");
    }
    return 0;
}