#include "Contact.hpp"

static std::string smallFormat(std::string string) {
    if (string.size() > 10)
    {
        return (string.substr(0,9) + ".");
    }
    else
    {
        return (string);
    }
}

void Contact::displayContact(void)
{
    std::cout << std::setw(10) << smallFormat(_first_name) << " | ";
    std::cout << std::setw(10) << smallFormat(_last_name) << " | ";
    std::cout << std::setw(10) << smallFormat(_nickname) << std::endl;
}

void Contact::printContact(void)
{
    std::cout << "First name is: " << _first_name << std::endl;
    std::cout << "Last name is: " << _last_name << std::endl;
    std::cout << "Nickname is: " << _nickname << std::endl;
    std::cout << "Phone number is: " << _phone_number << std::endl;
    std::cout << "Darkest secret is: " << _darkest_secret << std::endl;

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
    std::getline(std::cin, _first_name);
    while (emptyString(_first_name) == true)
    {
        std::cout << "Fill in First name: ";
        std::getline(std::cin, _first_name);
    }
    std::cout << "Fill in Last name: ";
    std::getline(std::cin, _last_name);
    while (emptyString(_last_name) == true)
    {
        std::cout << "Fill in Last name: ";
        std::getline(std::cin, _last_name);
    }
    std::cout << "Fill in Nickname: ";
    std::getline(std::cin, _nickname);
    while (emptyString(_nickname) == true)
    {
        std::cout << "Fill in Nickname: ";
        std::getline(std::cin, _nickname);
    }
    std::cout << "Fill in Phone number: ";
    std::getline(std::cin, _phone_number);
    while (emptyString(_phone_number) == true)
    {
        std::cout << "Fill in Phone number: ";
        std::getline(std::cin, _phone_number);
    }
    std::cout << "Fill in Darkest secret: ";
    std::getline(std::cin, _darkest_secret);
    while (emptyString(_darkest_secret) == true)
    {
        std::cout << "Fill in Darkest secret: ";
        std::getline(std::cin, _darkest_secret);
    }
    std::cout << std::endl;
    printContact();
    std::cout << std::endl;
}