#ifndef FORM_H

#define FORM_H
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _sign;
        const int _signGrade;
        const int _execGrade;

    public:
        Form(const std::string &inp_name, const int signGrade, const int execGrade);
        Form(const Form &obj);
        Form &operator=(const Form &obj);
        virtual ~Form() = 0;

        // Getters
        std::string getName() const;
        int getGradeSign() const;
        int getExecutedGrade() const;
        bool isSigned() const;

        // Public Member functions
        void beSigned(Bureaucrat &bureau);
        virtual void execute(Bureaucrat const &executor) = 0;

        // Exception functions
        class GradeTooHighException : std::exception
		{
			public:
				const char *what() const throw ()
                {
                    return ("Grade is too high!");
                }
		};
        class GradeTooLowException : std::exception
		{
			public:
				const char *what() const throw ()
                {
                    return ("Grade is too low!");
                }
		};
};

// Insertion overload operator
std::ostream& operator<<(std::ostream& out, const Form &form);

#endif
