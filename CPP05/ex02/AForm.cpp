#include "./include/AForm.hpp"
#include "./include/Bureaucrat.hpp"

AForm::AForm(const std::string &inp_name, const int signGrade, const int execGrade) : \
            _name(inp_name),  _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "Default constructor called" << std::endl;
    this->_sign = false;
    if (execGrade < 1)
    {
        throw AForm::GradeTooHighException();
    }
    if (execGrade > 150)
    {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm &obj) : _name(obj._name), _sign(obj._sign), \
                             _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

AForm& AForm::operator=(const AForm &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    _sign = obj._sign;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Destructor is called" << std::endl;
}

std::string AForm::getName() const
{
    return (this->_name);
}

int AForm::getGradeSign() const
{
    return (this->_signGrade);
}

int AForm::getExecutedGrade() const
{
    return (this->_execGrade);
}

bool AForm::isSigned() const
{
    return (this->_sign);
}

void AForm::beSigned(const Bureaucrat &bureau)
{
    if (bureau.getGrade() <= this->getGradeSign())
    {
        this->_sign = true;
    }
    else
    {
        this->_sign = false;
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() <= this->_execGrade)
    {
        std::cout << "Form executed" << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm &form)
{
    out << "Name " << form.getName() << " Grade to sign: " << form.getGradeSign() << \
        " Grade to execute: " << form.getExecutedGrade() << " is it signed: " << form.isSigned();
    return out;
}