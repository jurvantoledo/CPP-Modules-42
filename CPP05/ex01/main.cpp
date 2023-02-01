#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "<< ---------- BUREAUCRAT WITH VALID GRADE ---------- >>" << std::endl;
    try
    {
        Bureaucrat jan("Jan", 45);
        Form form1("Form 1", 50, 100);
        std::cout << jan << std::endl; 
        std::cout << form1 << std::endl;

        jan.signForm(form1);
        std::cout << std::endl << std::endl;
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