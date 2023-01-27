#ifndef BUREAUCRAT_H

#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();


        // Exception functions
        void GradeTooHighException();
        void GradeTooLowException();

        // Member functions
        std::string getName() const;
        int getGrade() const;

    private:
        std::string _name;
        int _grade;
};

#endif