#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
	private:
		std::string _file;
		std::map<std::string, float>	_map;
		float	getPrice(std::string date);

	public:
		BitcoinExchange(std::string input);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange & operator = (const BitcoinExchange &obj);
		~BitcoinExchange();

		void	getFile();
		void	getCSVFile();

		class NoValidPriceException : public std::exception
		{
			public:
                const char *what() const throw();
		};

		class NoValidInputException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif