#include "../include/RPN.hpp"

int	main(int argc, char *argv[])
{
	int	res;
	if (argc != 2)
	{
		std::cout << "Bruh are you dumb" << std::endl;
		return (0);
	}

	RPN weirdaf(argv[1]);

	try
	{
		res = weirdaf.CheckRPN();
		std::cout << "The result: " << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}