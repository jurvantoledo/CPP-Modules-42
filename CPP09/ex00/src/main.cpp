#include "../include/BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Not enough arguments" << std::endl;
		return (1);
	}
	
	BitcoinExchange bit(argv[1]);

	bit.ReadFile();
	return (0);
}
