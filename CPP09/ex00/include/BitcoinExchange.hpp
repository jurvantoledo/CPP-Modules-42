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
		std::vector<std::string> _valArr;
		std::vector<std::string> _dateArr;

	public:
		BitcoinExchange(std::string input);
		~BitcoinExchange();

		void	ReadTextFile();
		std::map<std::string, std::string>	ReadCSVFile();
		void	CompareFiles();
		int		ValueChecks(std::string value);
		int		DateChecks(std::string dates);

};

#endif