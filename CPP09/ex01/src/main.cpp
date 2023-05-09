#include "../include/RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Bruh are you dumb" << std::endl;
		return (0);
	}

	RPN weirdaf(argv[1]);

	weirdaf.CheckRPN();
	return (0);
}