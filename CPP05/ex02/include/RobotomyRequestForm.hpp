#ifndef ROBOT_REQUEST_FORM_H

#define ROBOT_REQUEST_FORM_H
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
    
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor);
};

#endif