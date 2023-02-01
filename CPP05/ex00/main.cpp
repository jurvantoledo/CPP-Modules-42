#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "<< ---------- BUREAUCRAT WITH VALID GRADE ---------- >>" << std::endl;
    try
    {
        Bureaucrat jan("Jan", 25);
        std::cout << jan << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "<< ---------- BUREAUCRAT WITH TOO HIGH INVALID GRADE ---------- >>" << std::endl;
    try
    {
        Bureaucrat jan("Jan", 151);
        std::cout << jan << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "<< ---------- BUREAUCRAT WITH TOO LOW INVALID GRADE ---------- >>" << std::endl;
    try
    {
        Bureaucrat jan("Jan", 0);
        std::cout << jan << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    return (0);
}