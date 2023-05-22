#include "./include/Bureaucrat.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/Form.hpp"
#include "./include/Intern.hpp"

int main()
{
    std::cout << "<< ---------- BUREAUCRAT ---------- >>" << std::endl;
    try
    {
        Intern one;
        Bureaucrat henk("Henk", 4);
        Form* robot;
        robot = one.makeForm("robotomy", "The boss man");
        std::cout << std::endl;
        henk.signForm(*robot);
        henk.executeForm(*robot);
        std::cout << std::endl;
        delete robot;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    std::cout << "<< ---------- BUREAUCRAT ---------- >>" << std::endl;
    try
    {
        Intern two;
        Bureaucrat kees("Kees", 10);
        Form* form2;
        std::cout << std::endl;
        form2 = two.makeForm("presidential", "The boss man");
        std::cout << std::endl;
        kees.signForm(*form2);
        kees.executeForm(*form2);
        std::cout << std::endl;
        delete form2;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl;
        std::cerr << e.what() << '\n';
    }

    
    std::cout << std::endl;
    std::cout << "<< ---------- BUREAUCRAT WITH INVALID GRADE ---------- >>" << std::endl;
    try
    {
        Intern two;
        Bureaucrat kees("Kees", 146);
        Form* form3;
        std::cout << std::endl;
        form3 = two.makeForm("shrubbery", "trees");
        std::cout << std::endl;
        kees.signForm(*form3);
        kees.executeForm(*form3);
        std::cout << std::endl;
        delete form3;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl;
        std::cerr << e.what() << '\n';
    }
    return (0);
}