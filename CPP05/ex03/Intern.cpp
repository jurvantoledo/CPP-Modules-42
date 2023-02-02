#include "./include/Intern.hpp"

Intern::Intern()
{
    std::cout << "Default constructors called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    std::cout << "Copy constructors called" << std::endl;
    *this = obj;
}

Intern& Intern::operator=(const Intern &obj)
{
    std::cout << "Cpoy assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Destructor is called" << std::endl;
}