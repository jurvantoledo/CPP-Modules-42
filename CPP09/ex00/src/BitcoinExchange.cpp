#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

BitcoinExchange::BitcoinExchange(std::string input)
{
	std::cout << "Constructor is called" << std::endl;
	this->_file = input;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "~Destructor is called" << std::endl;
}

std::map<std::string, std::string>	BitcoinExchange::ReadCSVFile()
{
	std::fstream csv_file;
	std::string	lines;
	std::string	dates;
	std::string values;
	std::map<std::string, std::string> map;

	csv_file.open ("include/data.csv");
	if (csv_file.is_open())
	{
		while (csv_file)
		{
			std::getline(csv_file, lines);
			std::size_t pos = lines.find(",");
			if (pos != std::string::npos)
				values = lines.substr(pos + 1);
			dates = lines.substr(0, 10);
			// std::cout << dates << " | " << values << std::endl;
			map[dates] = values;
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;
	return (map);
}

void	BitcoinExchange::ValueChecks(std::string value)
{

}

void	BitcoinExchange::ReadTextFile()
{
	std::vector<std::string> valArray;
	std::vector<std::string> dateArray;
	std::string lines;
	std::string dates;
	std::string value;
	std::map<std::string, std::string> map;

	std::fstream o_file (this->_file);
	if (o_file.is_open())
	{
		while (o_file)
		{
			std::getline(o_file, lines);

			lines.erase(std::remove_if(lines.begin(), lines.end(), ::isspace), lines.end());
			std::size_t pos = lines.find("|");
			if (pos != std::string::npos)
			{
				value = lines.substr(pos + 1);
				if (value.size() == 0)
				{
					std::cout << "Error: No value found" << std::endl;
				}
				
			}
			valArray.push_back(value);

			dates = lines.substr(0, lines.find_first_of("|"));
			dateArray.push_back(dates);
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;

	this->_valArr = valArray;
	this->_dateArr = dateArray;
	o_file.close();
}

void	BitcoinExchange::CompareFiles()
{
	std::map<std::string, std::string> map;
	int		int_check = 0;
	double	val = 0;

	map = ReadCSVFile();
	std::map<std::string, std::string>::iterator it = map.begin();
	// while (it != map.end())
	// {
	// 	std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	// 	++it;
	// }
	// for (size_t i = 0; i < _dateArr.size(); i++)
	// {
	// 	std::cout << this->_dateArr[i] << "lol" << std::endl;
	// }
	while (it != map.end())
	{
		for (size_t i = 0; i < _dateArr.size(); i++)
		{
			if (strcmp(it->first.c_str(), this->_dateArr[i].c_str()) == 0)
			{
				// std::cout << "Date in map: " << it->first << " Date in array: " << this->_dateArr[i] << std::endl;
				// std::cout << "Date in map: " << it->second << " Date in array: " << this->_valArr[i] << std::endl;
				val = atof(this->_valArr[i].c_str()) * atof(it->second.c_str());
				int_check = static_cast<int>(atoi(this->_valArr[i].c_str()));
				// if (int_check >= 0 && int_check <= INT_MAX)
				// {
				// 	std::cout << it->first << " => " << this->_valArr[i] << " = " << val << std::endl;
				// }
				// else if (int_check < 0)
				// {
				// 	std::cout << "Error: " << "Not a positive number" << std::endl;
				// }
				// else if (int_check >= INT_MAX)
				// {
				// 	std::cout << "Error: " << "Too largen number" << std::endl;
				// }
			}
		}
		++it;
	}
}

