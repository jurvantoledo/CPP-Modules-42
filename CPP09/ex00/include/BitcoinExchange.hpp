#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::string _file;
		std::vector<std::string> _valArr;

	public:
		BitcoinExchange(std::string input);
		~BitcoinExchange();

		void	ReadTextFile();
		void	ReadCSVFile();
};

#endif