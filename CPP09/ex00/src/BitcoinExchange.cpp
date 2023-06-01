#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

BitcoinExchange::BitcoinExchange(std::string input)
{
	this->_file = input;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &obj)
{
	this->_map = obj._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


void	BitcoinExchange::getCSVFile()
{
	std::ifstream	file("./include/data.csv");
	if (!file.is_open())
		throw BitcoinExchange::NoValidInputException();
	
	std::string	delim(",");
	std::string line;
	while (std::getline(file, line))
	{
		try
		{
			struct tm tm;
			std::string date = line.substr(0, line.find(delim));
			std::string value = line.substr(date.length() + delim.length());

			if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
				throw BitcoinExchange::NoValidPriceException();

			float rate = 0.0f;
			std::stringstream conv;
			conv << value;
			conv >> rate;

			this->_map.insert(std::pair<std::string,float>(date,rate));
		}
		catch(const std::exception& e) {}
		
	}
	if (!this->_map.size())
	{
		throw std::runtime_error("No prices available");
	}
}

void	BitcoinExchange::getFile() 
{
	std::ifstream	file(this->_file);
	if (!file.is_open())
		throw BitcoinExchange::NoValidInputException();

	std::string	delim(" | ");
	std::string line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			if (line.find(delim) == std::string::npos)
			{
				throw std::runtime_error(std::string("bad input => ") + line);
			}
			
			struct tm tm;
			std::string date	= line.substr(0, line.find(delim));
			std::string value	= line.substr(date.length() + delim.length());

			if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
				throw std::runtime_error("invalid date");
			
			float rate = 0.0f;
			std::stringstream conv;
			conv << value;
			conv >> rate;

			if (rate > 1000)
			{
				throw std::runtime_error("number is too large");
			}
			if (rate < 0)
			{
				throw std::runtime_error("number is not positive");
			}
			if (date < _map.begin()->first)
			{
				throw std::runtime_error(std::string("no history on/before date ") + date);
			}
	
			std::cout << date << " => " << rate << " = " << this->getPrice(date) * rate << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

float	BitcoinExchange::getPrice(std::string date)
{
	std::map<std::string, float>::iterator it;

	for (it = this->_map.end(); it != this->_map.begin(); it--)
	{
		if (date >= it->first)
			return (it->second);
	}
	return (it->second);
}

const char* BitcoinExchange::NoValidPriceException::what(void) const throw()
{
	return "Couldn't find prices or was not able to open file";
}

const char* BitcoinExchange::NoValidInputException::what(void) const throw()
{
	return "Couldn't open input file";
}