#include "../include/RPN.hpp"

int	main(int argc, char *argv[])
{
	int	res;
	if (argc != 2)
	{
		std::cout << "Bruh" << std::endl;
		return (0);
	}


	try
	{
		RPN weirdaf(argv[1]);
		res = weirdaf.checkRPN();
		std::cout << "The result: " << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}