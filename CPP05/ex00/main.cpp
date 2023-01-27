#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureau("Jan", 20);

    std::cout << std::endl;
    std::cout << "<< ---------- BUREAUCRAT ---------- >>" << std::endl;
    std::cout << bureau.getName() << std::endl;
    std::cout << bureau.getGrade() << std::endl;
    std::cout << std::endl;

    return (0);
}