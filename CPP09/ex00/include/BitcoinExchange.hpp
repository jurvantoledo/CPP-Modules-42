#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class BitcoinExchange
{
	private:
		std::string _file;

	public:
		BitcoinExchange(std::string input);
		~BitcoinExchange();

		void	ReadFile();
		void	UseFile(std::vector<std::string> row);
};

#endif