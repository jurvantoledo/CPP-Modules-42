#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &c)
{
	*this = c;
}

RPN::~RPN()
{
}

RPN &RPN::operator = (const RPN &c)
{
	(void)c;
	return (*this);
}

int RPN::evaluate(char* _input)
{
	std::stringstream	input(_input);
	std::string			operators("+-*/");
	std::stack<int>		stack;
	char				token;

	while (input >> token) {
        if (operators.find(token) != std::string::npos) {
            if (stack.size() < 2)
				throw std::runtime_error("insufficient operands");

            int n2 = stack.top(); stack.pop();
            int n1 = stack.top(); stack.pop();
            int res;

            if (token == '+')
                res = n1 + n2;
            else if (token == '-')
                res = n1 - n2;
            else if (token == '*')
                res = n1 * n2;
            else if (token == '/') {
                if (n2 == 0) 
					throw std::runtime_error("division by zero");
                res = n1 / n2;
            }
            stack.push(res);
        }
        else
		{
			if (token < '0' || token > '9')
				throw std::runtime_error("bad input");
            int num = token - '0';
            stack.push(num);
        }
    }
	if (stack.size() != 1)
		throw std::runtime_error("stack size is not exactly one at end of evaluation");
	return (stack.top());
}