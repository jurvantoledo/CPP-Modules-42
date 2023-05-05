#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input)
{
	std::cout << "Constructor is called" << std::endl;
	this->_file = input;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "~Destructor is called" << std::endl;
}

std::map<std::string, std::string>	BitcoinExchange::ReadCSVFile()
{
	std::fstream csv_file;
	std::string	lines;
	std::string	dates;
	std::string values;
	std::map<std::string, std::string> map;

	csv_file.open ("include/data.csv");
	if (csv_file.is_open())
	{
		while (csv_file)
		{
			std::getline(csv_file, lines);
			std::size_t pos = lines.find(",");
			if (pos != std::string::npos)
				values = lines.substr(pos + 1);
			dates = lines.substr(0, 10);
			// std::cout << dates << " | " << values << std::endl;
			map[dates] = values;
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;
	return (map);
}

std::vector<std::vector<std::string> >	BitcoinExchange::ReadTextFile()
{
	std::vector<std::vector<std::string> > content;
	std::vector<std::string> row;
	std::string line;
	std::string word;

	std::fstream o_file (this->_file);
	if (o_file.is_open())
	{
		while (o_file)
		{
			row.clear();
			std::getline(o_file, line);

			std::stringstream str(line);
			while (std::getline(str, word, '|'))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		std::cout << "Could not open the file or file does not exist" << std::endl;
	o_file.close();
	return (content);
}

void	BitcoinExchange::CompareFiles()
{
	std::map<std::string, std::string> map;
	std::vector<std::vector<std::string> > content;

	map = ReadCSVFile();
	content = ReadTextFile();
	// std::map<std::string, std::string>::iterator it = map.begin();
	// while (it != map.end())
	// {
	// 	std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	// 	++it;
	// }
	for (size_t i = 0; i < content.size(); i++)
	{
		for (size_t j = 0; j < content[i].size(); j++)
		{
			std::cout << content[i][j] <<  "";
		}
		std::cout << std::endl;
	}
}