#include "./include/RobotomyRequestForm.hpp"
#include "./include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), \
                                                                    _target(target)
{
    std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target)
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
        std::cout << this->_target << " Makes some drilling noises." << std::endl;
        std::srand(time(NULL));
        if (std::rand() % 2)
        {
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        }
        else
        {
            std::cout << this->_target << " has failed failed tremendously." << std::endl;
        }
    }
    
}