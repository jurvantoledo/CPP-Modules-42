#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
	private:
		std::string _file;
		std::vector<std::string> _valArr;

	public:
		BitcoinExchange(std::string input);
		~BitcoinExchange();

		std::vector<std::vector<std::string> >	ReadTextFile();
		std::map<std::string, std::string>	ReadCSVFile();
		void	CompareFiles();
};

#endif