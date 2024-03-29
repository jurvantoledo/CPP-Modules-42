#include "../include/RPN.hpp"

RPN::RPN(std::string input) : _data(input) {}

RPN::~RPN() {}

const char* RPN::NoNumbersException::what(void) const throw()
{
	return "Error";
}

const char* RPN::WrongAmountException::what(void) const throw()
{
	return "Error: wrong amount of numbers and operators or numbers are too high";
}

int	RPN::checkOperators(char c)
{
	if (c == '*' || \
		c  == '-' || \
		c == '+' || \
		c == '/')
		return (1);
	return (0);
}

int	RPN::amountOfNumbersAndOperators()
{
	int	count_digits = 0;
	int	count_operators = 0;

	for (size_t i = 0; i < _data.size(); i++)
	{
		if (isdigit(_data[i]))
			count_digits++;
		if (checkOperators(_data[i]))
			count_operators++;
	}
	if (count_operators >= count_digits || count_operators == 0 || count_digits - 1 != count_operators)
		return (1);
	return (0);
}

int RPN::checkRPN()
{
	std::stack<int> stack;
	int	res = 0;
	int	num_count = 0;

	if (_data.size() == 0)
		throw (NoNumbersException());

	for (size_t i = 0; i < _data.size(); i++)
	{
		if (isdigit(_data[i]))
		{
			if (amountOfNumbersAndOperators())
				throw (WrongAmountException());
			if (_data[i] >= '0' && _data[i] <= '9' && \
				_data[i + 1] != ' ' && \
				_data[i + 1] != '+' && _data[i + 1] != '-' && \
				_data[i + 1] != '*' && _data[i + 1] != '/')
				throw (WrongAmountException());
			int num = _data[i] - '0';
			num_count++;
			stack.push(num);
		}
		else if (checkOperators(_data[i]) \
				&& !amountOfNumbersAndOperators())
		{
			if (num_count <= 1)
				throw (NoNumbersException());
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
			stack.push(res);
		}
		else
		{
			if (!isspace(_data[i]))
				throw(NoNumbersException());
		}
	}
	return stack.top() ;
}
