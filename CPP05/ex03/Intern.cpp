#include "./include/Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    std::cout << "Copy Constructor called" << std::endl;
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

Form* Intern::makeForm(std::string formName, std::string target)
{
    Form* makeForm = NULL;

    std::string formArray[] = {
        "robotomy",
        "presidential",
        "shrubbery"
    };

    

    int i = 0;
    while (i < 3)
    {
        if (formName == formArray[i])
        {
            break ;
        }
        i++;
    }
    if (i == 3)
    {
        throw InvalidArg();
    }
    switch (i)
    {
        case 0:
            makeForm = new RobotomyRequestForm(target);
            break;
        case 1:
            makeForm = new PresidentialPardonForm(target);
            break;
        case 2:
            makeForm = new ShrubberyCreationForm(target);
            break;
        default:
            break;
    }

    std::cout << "Intern created " << formArray[i] << std::endl;
    return makeForm;
}

const char *Intern::InvalidArg::what(void) const throw() 
{
    return "Invalid name in Intern form!";
}