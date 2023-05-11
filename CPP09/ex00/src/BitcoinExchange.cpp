#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

BitcoinExchange::BitcoinExchange(char* input)
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
	std::fstream o_file;
	std::string lines;
	std::string dates;
	std::string value;
	std::map<std::string, std::string> map;

	map = ReadCSVFile();
	o_file.open(this->_file);
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

			dates = lines.substr(0, lines.find_first_of("|"));
			if (static_cast<long>(atol(dates.c_str())) == 0)
				continue;
			if (ValueChecks(value) != 0 && DateChecks(dates))
			{
					GetClosestDate(map, dates);
			}
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;
	o_file.close();
}

int	BitcoinExchange::GetClosestDate(std::map<std::string, std::string> map, std::string &key)
{
	std::map<std::string, std::string>::iterator it = map.begin();

	for (it = map.begin(); it != map.end(); it++)
	{
		if (key.compare(it->first) == 0)
		{
			std::cout << it->first << " => " << it->second << " = " << atof(key.c_str()) * atof(it->second.c_str()) << std::endl;
			return (1);
		}
		if (key.compare(it->first) < 0)
		{
			std::cout << it->first << " => " << it->second << " = " << atof(key.c_str()) * atof(it->second.c_str()) << std::endl;
			return (2);
		}
	}
	return (0);
}

void BitcoinExchange::CompareFiles()
{
	std::map<std::string, std::string> map;

	map = ReadCSVFile();
	for (size_t i = 0; i < _dateArr.size(); i++)
	{
		if (ValueChecks(this->_valArr[i]) != 0 && DateChecks(this->_dateArr[i]) != 0)
		{
				GetClosestDate(map, this->_dateArr[i]);
		}
	}
}
