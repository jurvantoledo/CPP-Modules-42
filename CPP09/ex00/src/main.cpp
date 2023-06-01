#include "../include/BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange bit(argv[1]);

		bit.getCSVFile();
		bit.getFile();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
