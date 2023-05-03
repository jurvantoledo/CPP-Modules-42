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

void	BitcoinExchange::ReadFile()
{
	std::cin >> this->_file;

	std::cout << "lol" << this->_file << std::endl;
	std::vector<std::vector<std::string> > content;
	std::vector<std::string> row;
	std::string line;
	std::string word;

	std::cout << "lol" << this->_file << std::endl;
	std::fstream o_file (this->_file, std::ios::in);
	if (o_file.is_open())
	{
		while (std::getline(o_file, line))
		{
			row.clear();

			std::stringstream str(line);

			while (std::getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		std::cout << "Could not open the file" << std::endl;
	for (size_t i = 0; i < content.size(); i++)
	{
		for (size_t j = 0; j < content[i].size(); j++)
		{
			std::cout << content[i][j] <<  " ";
		}
		std::cout << std::endl;
	}
}