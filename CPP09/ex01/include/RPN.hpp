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

		int	CheckRPN();
};

#endif