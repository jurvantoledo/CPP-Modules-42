#include "Contact.hpp"

void Contact::displayContact(void)
{
    std::cout << "First name is: " << first_name << "|";
    std::cout << "Last name is: " << last_name << "|";
    std::cout << "Nickname is: " << nickname << std::endl;
}

void Contact::printContact(void)
{
    std::cout << "First name is: " << first_name << std::endl;
    std::cout << "Last name is: " << last_name << std::endl;
    std::cout << "Nickname is: " << nickname << std::endl;
    std::cout << "Phone number is: " << phone_number << std::endl;
    std::cout << "Darkest secret is: " << darkest_secret << std::endl;

}

static bool emptyString(std::string string)
{
    int i = 0;

    if (string.empty())
    {
        std::cout << "String cannot be empty" << std::endl;
        return (true);
    }
    else
    {
        while (string[i])
        {
            if (isspace(string[i]))
                i++;
            else
                return (false);
        }
    }
    std::cout << "String cannot be empty" << std::endl;
    return (true);
    
}

void Contact::setContact() 
{
    std::cout << "Fill in First name: ";
    std::getline(std::cin, first_name);
    while (emptyString(first_name) == true)
    {
        std::cout << "Fill in First name: ";
        std::getline(std::cin, first_name);
    }
    std::cout << "Fill in Last name: ";
    std::getline(std::cin, last_name);
    while (emptyString(last_name) == true)
    {
        std::cout << "Fill in Last name: ";
        std::getline(std::cin, last_name);
    }
    std::cout << "Fill in Nickname: ";
    std::getline(std::cin, nickname);
    while (emptyString(nickname) == true)
    {
        std::cout << "Fill in Nickname: ";
        std::getline(std::cin, nickname);
    }
    std::cout << "Fill in Phone number: ";
    std::getline(std::cin, phone_number);
    while (emptyString(phone_number) == true)
    {
        std::cout << "Fill in Phone number: ";
        std::getline(std::cin, phone_number);
    }
    std::cout << "Fill in Darkest secret: ";
    std::getline(std::cin, darkest_secret);
    while (emptyString(darkest_secret) == true)
    {
        std::cout << "Fill in Darkest secret: ";
        std::getline(std::cin, darkest_secret);
    }
    std::cout << std::endl;
    printContact();
}