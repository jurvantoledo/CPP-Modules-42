#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &input_name, int grade) : name(input_name), grade(grade)
{
    std::cout << "Default Constructor is called" << std::endl;
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    std::cout << "Copy Constructor is called" << std::endl;
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    this->grade = obj.getGrade();
    return (*this);
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor is called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureau)
{
    o << "name: " << bureau.getName() << " , grade: " << bureau.getGrade();
    return o;
}