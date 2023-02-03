#include "./include/RobotomyRequestForm.hpp"
#include "./include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), \
                                                                    _target(target)
{
    std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : Form(obj), _target(obj._target)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor is called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() <= this->getExecutedGrade())
    {
        if (rand() & 1)
        {
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        }
        else
        {
            std::cout << this->_target << " Makes some drilling noises." << std::endl;
        }
    }
    
}