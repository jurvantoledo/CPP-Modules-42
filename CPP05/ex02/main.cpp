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
        Bureaucrat jan("Jan", 25);
        PresidentialPardonForm pres("De baas");
        std::cout << std::endl;
        jan.signForm(pres);
        jan.executeForm(pres);
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (AForm::GradeTooHighException& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "<< --------------------------------------- >>" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat kees("Kees", 72);
        RobotomyRequestForm robot("cool");
        std::cout << std::endl;
        kees.signForm(robot);
        kees.executeForm(robot);
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (AForm::GradeTooHighException& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "<< --------------------------------------- >>" << std::endl;
    std::cout << std::endl;
    std::cout << "<< --------------------------------------- >>" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat henk("Henk", 145);
        ShrubberyCreationForm shrub("lol");
        std::cout << std::endl;
        henk.signForm(shrub);
        henk.executeForm(shrub);
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (AForm::GradeTooHighException& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    return (0);
}