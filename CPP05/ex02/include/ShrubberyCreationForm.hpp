#ifndef SHRUB_CREATE_FORM_H

#define SHRUB_CREATE_FORM_H
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor);
};

#endif