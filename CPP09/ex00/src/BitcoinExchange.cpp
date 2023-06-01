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
	(void)obj;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


void	BitcoinExchange::getFile() 
{
	std::fstream	file(this->_file);
	if (!file.is_open())
		throw BitcoinExchange::NoValidInputException();

	
}

const char* BitcoinExchange::NoValidInputException::what(void) const throw()
{
	return "Could not open input file";
}