#include "../include/RPN.hpp"

RPN::RPN(std::string input) : _data(input)
{
}

RPN::~RPN()
{
}

int RPN::CheckRPN()
{
	std::stack<int> stack;
	int	res = 0;

	for (size_t i = 0; i < _data.size(); i++)
	{
		if (isdigit(_data[i]))
		{
			if ((_data[i] >= '0' && _data[i] <= '9') && _data[i + 1] != ' ')
			{
				std::cout << "Number is too high!" << std::endl;
				return (0);
			}
			int num = _data[i] - '0';
			std::cout << num << std::endl;
			stack.push(num);
		}
		else if (_data[i] == '*' || _data[i] == '-' || _data[i] == '+' || _data[i] == '/')
		{
			int y = stack.top();
			stack.pop();
			int x = stack.top();
			stack.pop();

			switch (_data[i])
			{
				case '*':
					res = x * y;
					break;
				case '-':
					res = x - y;
					break;
				case '+':
					res = x + y;
					break;
				case '/':
					res = x / y;
					break;
				default:
					break;
			}
			std::cout << res << std::endl;
			stack.push(res);
		}
		else
		{
			if (!isspace(_data[i]))
			{
				std::cout << "The math aint mathing bro" << std::endl;
				return (0);
			}
		}
	}
	return stack.top() ;
}