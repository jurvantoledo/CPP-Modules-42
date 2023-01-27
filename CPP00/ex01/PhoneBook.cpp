#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _index = 0;
    return ;
}

PhoneBook::~PhoneBook()
{
    
}

void PhoneBook::showPhoneBook(void)
{
    int i = 0;
    std::cout << std::endl << std::setw(10) << "INDEX" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < _index; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        _contacts[i].displayContact();
    }
    std::cout << std::endl;
}

void PhoneBook::searchContact(void)
{
    if (_index == 0)
    {
        std::cout << "No contacts in your phonebook" << std::endl;
        return ;
    }

    std::cout << "This are the contacts in your phonebook" << std::endl;
    showPhoneBook();

    std::string str_idx;
    bool        active = true;

    std::cout << "Enter index of contact to see full info" << std::endl;
    while (active)
    {
        std::cout << "Enter the index: ";
        std::getline(std::cin, str_idx);
        int i = atoi(str_idx.c_str());

        if (i < 1 || i > _index)
        {
            std::cout << "Contact does not exists. Choose number between 1 and " << _index << std::endl;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "---------------" << std::endl;
            _contacts[i - 1].printContact();
            active = false;
            std::cout << "---------------" << std::endl;
        }
    }
    std::cout << std::endl;

}

void PhoneBook::removeContact(void)
{
    for (int i = 0; i < 7; i++)
    {
        _contacts[i] = _contacts[i + 1];
    }
    
}

void PhoneBook::addContact(void) 
{
    _index++;
    if (_index > 8)
    {
        std::cout << "Phonebook is full, deleting oldest contact" << std::endl;
        removeContact();
        _index--;
    }
    _contacts[_index - 1].setContact();
}