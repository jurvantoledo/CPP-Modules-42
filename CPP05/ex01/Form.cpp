#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &inp_name, const int signGrade, const int execGrade) : \
            _name(inp_name),  _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "Default constructor called" << std::endl;
    if (execGrade < 1)
    {
        throw Form::GradeTooHighException();
    }
    if (execGrade > 150)
    {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &obj) : _name(obj._name), _sign(obj._sign), \
                             _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Form& Form::operator=(const Form &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)&obj;
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor is called" << std::endl;
}

std::string Form::getName() const
{
    return (this->_name);
}

int Form::getGradeSign() const
{
    return (this->_signGrade);
}

int Form::getExecutedGrade() const
{
    return (this->_execGrade);
}

bool Form::isSigned() const
{
    return (this->_sign);
}

void Form::beSigned(Bureaucrat &bureau)
{
    if (bureau.getGrade() <= this->getGradeSign())
    {
        this->_sign = true;
    }
    else
    {
        this->_sign = false;
        throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, const Form &form)
{
    out << "Name " << form.getName() << " Grade to sign: " << form.getGradeSign() << \
        " Grade to execute: " << form.getExecutedGrade() << " is it signed: " << form.isSigned();
    return out;
}