#ifndef INTERN_H

#define INTERN_H
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        /* data */
    
    public:
        Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        ~Intern();

        Form *makeForm(std::string formName, std::string target);

		class InvalidArg : public std::exception
		{
			public:
				const char *what() const throw ();
		};
};

#endif