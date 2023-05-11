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
        std::cout << std::endl;
        std::cout << jan << std::endl; 
        std::cout << form1 << std::endl;

        jan.signForm(form1);
        std::cout << std::endl << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat kees("Kees", 45);
        Form form2("Form 2", 40, 100);
        std::cout << std::endl;
        std::cout << kees << std::endl; 
        std::cout << form2 << std::endl;

        kees.signForm(form2);
        std::cout << std::endl << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}