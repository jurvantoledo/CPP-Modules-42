#include "../include/RPN.hpp"

RPN::RPN(std::string input) : _data(input)
{
	std::cout << "Constructor is calles" << std::endl;
}

RPN::~RPN()
{
	std::cout << "Destructor is calles" << std::endl;
}

void RPN::CheckRPN()
{
	std::stack<int> stack;
	std::cout << "The input: " << this->_data << std::endl;

	for (size_t i = 0; i < _data.size(); i++)
	{
		std::cout << "The characters: " << _data[i] << std::endl;
	}
}