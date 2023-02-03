#ifndef PRES_PARDON_FORM_H

#define PRES_PARDON_FORM_H
#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
    private:
        const std::string _target;
    
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor);
};

#endif