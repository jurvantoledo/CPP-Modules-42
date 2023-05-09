#ifndef RPN_H
#define RPN_H
#include <iostream>

class RPN
{
	private:
		std::string _data;

	public:
		RPN(std::string input);
		~RPN();

		void	CheckRPN();
};

#endif