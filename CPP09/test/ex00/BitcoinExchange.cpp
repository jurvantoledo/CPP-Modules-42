#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &c)
{
	*this = c;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &c)
{
	this->_price_history = c._price_history;
	return (*this);
}

void BitcoinExchange::loadHistory(void)
{
	std::ifstream	file("./data.csv");
	if (!file.is_open())
		throw BitcoinExchange::NoValidHistoryFileException();
	
	std::string	delim(",");
	std::string	line;
	while (std::getline(file, line))
	{
		try
		{
			struct tm tm;
			std::string date	= line.substr(0, line.find(delim));
			std::string value	= line.substr(date.length() + delim.length()); 

			if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
				throw BitcoinExchange::NoValidHistoryFileException();
			
			float rate = 0.0f;
			std::stringstream conv;
			conv << value;
			conv >> rate;

			this->_price_history.insert(std::pair<std::string,float>(date,rate));
		}
		catch(const std::exception& e) {}
	}
	if (!this->_price_history.size())
		throw std::runtime_error("no price history available");
}

void BitcoinExchange::processFile(std::string filename)
{
	std::ifstream	file(filename);
	if (!file.is_open())
		throw BitcoinExchange::NoValidInputFileException();

	std::string	delim(" | ");
	std::string	line;
	while (std::getline(file, line))
	{
		try
		{
			if (line.find(delim) == std::string::npos)
				throw std::runtime_error(std::string("bad input => ") + line);

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
				throw std::runtime_error("number is too large");
			if (rate < 0)
				throw std::runtime_error("number is not positive");
			if (date < _price_history.begin()->first)
				throw std::runtime_error(std::string("no history on/before date ") + date);
			
			std::cout << date << " => " << rate << " = " << this->getPrice(date) * rate << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

float BitcoinExchange::getPrice(std::string date)
{
	std::map<std::string,float>::iterator	it = this->_price_history.end();
	while (it != this->_price_history.begin())
	{
		if (date >= it->first)
			return (it->second);
		it--;
	}
	return (it->second);
}

const char* BitcoinExchange::NoValidHistoryFileException::what(void) const throw()
{
	return "Could not find price history file (data.csv) or was not able to open it";
}

const char* BitcoinExchange::NoValidInputFileException::what(void) const throw()
{
	return "Could not open input file";
}
