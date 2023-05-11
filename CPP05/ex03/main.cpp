#include "./include/Bureaucrat.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/Form.hpp"
#include "./include/Intern.hpp"

void    f()
{
    system("leaks bureau");
}

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
    return (0);
}