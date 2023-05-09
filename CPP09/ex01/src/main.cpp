#include "../include/RPN.hpp"

int	main(int argc, char *argv[])
{
	// int	res;
	if (argc != 2)
	{
		std::cout << "Bruh are you dumb" << std::endl;
		return (0);
	}

	RPN weirdaf(argv[1]);

	weirdaf.CheckRPN();
	// std::cout << "The answer of weirdaf: " << res << std::endl;
	return (0);
}