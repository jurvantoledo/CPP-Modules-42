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
        class GradeTooHighException : std::exception
		{
			public:
				const char *what() const throw ();
				//{
				//	return "Grade is to low";
				//}
		};
        class GradeTooLowException : std::exception
		{
			public:
				const char *what() const throw ();
				//{
				//	return "Grade is to low";
				//}
		};

    private:
        const std::string name;
        int grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureau);

#endif