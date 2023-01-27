#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    std::cout << "Default Constructor is called" << std::endl;
    this->_name = name;
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    std::cout << "Copy Constructor is called" << std::endl;
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    this->_name = obj._name;
    this->_grade = obj._grade;
    return (*this);
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor is called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}