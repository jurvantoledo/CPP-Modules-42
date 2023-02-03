#include "./include/Bureaucrat.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/Form.hpp"
#include "./include/Intern.hpp"

int main()
{
    std::cout << "<< ---------- BUREAUCRAT ---------- >>" << std::endl;
    std::cout << std::endl;
    Intern one;
    Bureaucrat henk("Henk", 4);
    Form* pres;
    pres = one.makeForm("robotomy", "The boss man");
    henk.signForm(*pres);
    henk.executeForm(*pres);
    std::cout << std::endl;
    return (0);
}