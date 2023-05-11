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
		char* _file;
		std::vector<std::string> _valArr;
		std::vector<std::string> _dateArr;

	public:
		BitcoinExchange(char* input);
		~BitcoinExchange();

		void	ReadTextFile();
		std::map<std::string, std::string>	ReadCSVFile();
		void	CompareFiles();
		int		ValueChecks(std::string value);
		int		DateChecks(std::string dates);
		int		GetClosestDate(std::map<std::string, std::string> map, std::string &key);


};

#endif