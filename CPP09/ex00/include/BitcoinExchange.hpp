#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::string _file;
	public:
		BitcoinExchange(std::string input);
		~BitcoinExchange();

		void	ReadFile();
};

#endif