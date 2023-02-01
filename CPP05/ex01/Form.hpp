#ifndef FORM_H

#define FORM_H
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    public:
        Form(const std::string &inp_name, bool sign, const int signGrade, const int execGrade);
        Form(const Form &obj);
        Form &operator=(const Form &obj);
        ~Form();

        // Member functions
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void beSigned(Bureaucrat& bureau);

        // Exception functions
        class GradeTooHighException : std::exception
		{
			public:
				const char *what() const throw ();
		};
        class GradeTooLowException : std::exception
		{
			public:
				const char *what() const throw ();
		};

    private:
        const std::string _name;
        bool _sign;
        const int _signGrade;
        const int _execGrade;
};

// Insertion overload operator
std::ostream& operator<<(std::ostream& o, const Form& form);

#endif
