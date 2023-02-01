#include "Form.hpp"

Form::Form(const std::string &inp_name, bool sign, const int signGrade, const int execGrade) : _name(inp_name), _sign(sign), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form &obj) : _name(obj._name), _sign(obj._sign), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Form& Form::operator=(const Form &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor is called" << std::endl;
}