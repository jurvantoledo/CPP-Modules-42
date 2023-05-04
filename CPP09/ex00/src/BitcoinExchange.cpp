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

void	BitcoinExchange::ReadCSVFile()
{
	std::fstream csv_file;
	std::string	line;
	std::map<std::string, std::string> map;

	csv_file.open ("include/data.csv");
	if (csv_file.is_open())
	{
		while (csv_file)
		{
			std::getline(csv_file, line);

		}
	}
	std::map<std::string, std::string>::iterator it = map.begin();
	while (it != map.end())
	{
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		++it;
	}
	
}

void	BitcoinExchange::ReadTextFile()
{
	std::vector<std::string> valArray;
	std::vector<std::string> dateArray;
	std::string dates;
	std::string value;
	std::map<std::string, std::string> map;

	std::ifstream o_file (this->_file);
	if (o_file.is_open())
	{
		while (o_file)
		{
			std::getline(o_file, dates, '\n');
			std::size_t pos = dates.find("|");
			if (pos == std::string::npos)
			{
				continue ;
			}
			value = dates.substr(pos + 1);
			valArray.push_back(value);
			dates = dates.substr(0, dates.find_first_of("|"));
			dateArray.push_back(dates);
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;
	this->_valArr = valArray;
	for (size_t i = 0; i < dateArray.size(); i++)
	{
		std::cout << "Dates: " << dateArray[i] << std::endl;
	}
	for (size_t i = 0; i < valArray.size(); i++)
	{
		std::cout << "Values: " << this->_valArr[i] << std::endl;
	}
	o_file.close();
}