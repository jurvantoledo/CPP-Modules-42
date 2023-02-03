#ifndef AFORM_H

#define AFORM_H
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _sign;
        const int _signGrade;
        const int _execGrade;

    public:
        AForm(const std::string &inp_name, const int signGrade, const int execGrade);
        AForm(const AForm &obj);
        AForm &operator=(const AForm &obj);
        virtual ~AForm() = 0;

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
std::ostream& operator<<(std::ostream& out, const AForm &form);

#endif
