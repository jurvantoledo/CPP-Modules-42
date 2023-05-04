#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input)
{
	std::cout << "Constructor is called" << std::endl;
	this->_file = input;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "~Destructor is called" << std::endl;
}

void	BitcoinExchange::UseFile(std::vector<std::string> row)
{
	std::string line;
	std::vector<std::string> value;
	std::vector<std::string> date;

	for (size_t i = 0; i < row.size(); i++)
	{
		// line = row[i].
		// date.push_back(line);
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		std::cout << date[i] << std::endl;
	}

	
}

void	BitcoinExchange::ReadFile()
{
	std::vector<std::string> row;
	std::string line;
	std::string word;

	std::ifstream o_file (this->_file);
	if (o_file.is_open())
	{
		while (o_file)
		{
			std::getline(o_file, line);
			row.push_back(line);
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;
	UseFile(row);
}