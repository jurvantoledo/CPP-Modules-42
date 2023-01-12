#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
    return ;
}

void PhoneBook::addContact(void) 
{
    index++;
    if (index > 0)
    {
        index--;
    }
    contacts[index - 1].setContact();
}