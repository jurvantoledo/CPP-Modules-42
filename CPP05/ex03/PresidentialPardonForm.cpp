#include "./include/PresidentialPardonForm.hpp"
#include "./include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), \
                                                                            _target(target)
{
    std::cout << "Default contstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : Form(obj), _target(obj._target)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor is called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() <= this->getExecutedGrade())
    {
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}