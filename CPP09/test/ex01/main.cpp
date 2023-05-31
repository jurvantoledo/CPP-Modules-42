#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "usage: ./RPN <input>" << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		int res = RPN::evaluate(argv[1]);
		std::cout << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
