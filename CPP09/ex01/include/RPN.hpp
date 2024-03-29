#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <stack>

class RPN
{
	private:
		std::string _data;


	public:
		RPN(std::string input);
		~RPN();

		int	checkRPN();
		int	checkOperators(char c);
		int	amountOfNumbersAndOperators();

		// Exceptions
		class NumbersTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

		class NoNumbersException : public std::exception
        {
            public:
                const char *what() const throw();
        };

		class WrongAmountException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif