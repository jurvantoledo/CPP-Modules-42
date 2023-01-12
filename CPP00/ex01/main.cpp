#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to secret phonebook" << std::endl;
    std::cout << "Choose one of the following options" << std::endl;
    std::cout << "ADD: add a contact to the phonebook" << std::endl;
    std::cout << "SEARCH: search a contact in the phonebook" << std::endl;
    std::cout << "EXIT: close and delete your phonebook" << std::endl;

    while (1)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            std::cout << "Make a function that searches for a user";
        }
        else if (command == "EXIT")
        {
            std::cout << "Make a function that exits the program and delete the phonebook";
            return (EXIT_SUCCESS);
        }
    }

    std::cout << "Program exit success" << std::endl;
    return (EXIT_SUCCESS);
}