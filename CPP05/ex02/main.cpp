#include "./include/Bureaucrat.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/AForm.hpp"

int main()
{
    std::cout << "<< ---------- BUREAUCRAT ---------- >>" << std::endl;
    std::cout << std::endl;
    try
    {
        std::cout << std::endl;
        Bureaucrat jan("Jan", 4);
        PresidentialPardonForm pres("Shit man");
        std::cout << std::endl;
        jan.signForm(pres);
        jan.executeForm(pres);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "<< --------------------------------------- >>" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat kees("Kees", 20);
        RobotomyRequestForm robot("cool");
        std::cout << std::endl;
        kees.signForm(robot);
        kees.executeForm(robot);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "<< --------------------------------------- >>" << std::endl;
    std::cout << std::endl;
    std::cout << "<< --------------------------------------- >>" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat henk("Henk", 40);
        ShrubberyCreationForm shrub("boom");
        std::cout << std::endl;
        henk.signForm(shrub);
        henk.executeForm(shrub);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}