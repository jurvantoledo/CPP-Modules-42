#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "usage: ./btc <input>" << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange	ex;

	try
	{
		ex.loadHistory();
		ex.processFile(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}
