#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    bool active = true;
    std::string command;

    std::cout << "Welcome to secret phonebook" << std::endl;
    std::cout << "Choose one of the following options" << std::endl;
    std::cout << "ADD: add a contact to the phonebook" << std::endl;
    std::cout << "SEARCH: search a contact in the phonebook" << std::endl;
    std::cout << "EXIT: close and delete your phonebook" << std::endl;

    while (active)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Closing phonebook" << std::endl;
            active = false;
        }
    }

    std::cout << "Program exit success" << std::endl;
    return (EXIT_SUCCESS);
}