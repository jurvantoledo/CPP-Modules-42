#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <string>
#include <exception>
#include <iterator>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &c);
    ~BitcoinExchange();
    BitcoinExchange & operator = (const BitcoinExchange &c);

	void	loadHistory();
	void	processFile(std::string filename);

	// exceptions

	class NoValidHistoryFileException: public std::exception
	{
	public:
		const char* what(void) const throw();
	};
	class NoValidInputFileException: public std::exception
	{
	public:
		const char* what(void) const throw();
	};
private:
	float	getPrice(std::string date);

	std::map<std::string, float>	_price_history;
};

#endif