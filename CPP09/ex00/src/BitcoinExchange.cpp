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

std::map<std::string, std::string> BitcoinExchange::ReadCSVFile()
{
	std::fstream csv_file;
	std::string lines;
	std::string dates;
	std::string values;
	std::map<std::string, std::string> map;

	csv_file.open("include/data.csv");
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

int BitcoinExchange::ValueChecks(std::string value)
{
	if (value.size() == 0)
	{
		std::cout << "Error: No value found" << std::endl;
		return (0);
	}
	else if (value[0] == '-')
	{
		std::cout << "Error: not a positive number" << std::endl;
		return (0);
	}
	else if (value.size() > 9)
	{
		std::cout << "Error: too large a number" << std::endl;
		return (0);
	}
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.')
		{
			std::cout << "Error: value is not a number" << std::endl;
			return (0);
		}
	}
	return (1);
}

// Thx Rolf :)
int BitcoinExchange::DateChecks(std::string dates)
{
	char	*newChar = strdup(dates.c_str());
	char *splitted_dates;

	if (dates.size() > 10)
		return (0);
    struct tm tm;
    if (!strptime(dates.c_str(), "%F", &tm)) {
        return 0;
    }
    std::stringstream year;
    int y;
    size_t found = dates.find("-");
    year << dates.substr(0, found);
    year >> y;
    if (y < 2009){
        return 0;
    }
	return (1);
}

void BitcoinExchange::ReadTextFile()
{
	std::vector<std::string> valArray;
	std::vector<std::string> dateArray;
	std::string lines;
	std::string dates;
	std::string value;
	std::map<std::string, std::string> map;

	std::fstream o_file(this->_file);
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
			}
			valArray.push_back(value);

			dates = lines.substr(0, lines.find_first_of("|"));
			if (static_cast<long>(atol(dates.c_str())) == 0)
				continue;
			dateArray.push_back(dates);
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;

	this->_valArr = valArray;
	this->_dateArr = dateArray;
	o_file.close();
}

void BitcoinExchange::CompareFiles()
{
	std::map<std::string, std::string> map;
	int int_check = 0;
	double val = 0;

	map = ReadCSVFile();
	std::map<std::string, std::string>::iterator it = map.begin();
	while (it != map.end())
	{
		for (size_t i = 0; i < _dateArr.size(); i++)
		{
			if (strcmp(it->first.c_str(), this->_dateArr[i].c_str()) == 0)
			{
				val = atof(this->_valArr[i].c_str()) * atof(it->second.c_str());
				int_check = static_cast<int>(atoi(this->_valArr[i].c_str()));
				if (int_check <= INT_MAX && ValueChecks(this->_valArr[i]) != 0 && DateChecks(this->_dateArr[i]) != 0)
				{
					std::cout << it->first << " => " << this->_valArr[i] << " = " << val << std::endl;
				}
			}
		}
		++it;
	}
}
