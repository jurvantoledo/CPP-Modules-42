#ifndef BUREAUCRAT_H

#define BUREAUCRAT_H

#include <iostream>

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(const std::string &input_name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();

        // Member functions
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(AForm &form);

        // Exception functions
        class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw ();
		};
        class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw ();
		};

    private:
        const std::string name;
        int grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureau);

#endif