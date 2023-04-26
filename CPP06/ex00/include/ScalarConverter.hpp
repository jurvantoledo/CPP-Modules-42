#ifndef SCALARCONVERTER_H

#define SCALARCONVERTER_H
#include <iostream>
#include <iomanip>


enum Type {
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	INVALID
};

class ScalarConverter {
	public:
		static void convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		~ScalarConverter();

		static std::string _value;
		static char _char;
		static int _int;
		static long _long;
		static float _float;
		static double _double;
		
		static int	getType();
		static void	printTypes();

		// Convert Functions
		static void ConvertChar();
		static void	ConvertInt();
		static void ConvertFloat();
		static void	ConvertDouble();

		// Display Functions
		static void	DisplayChar();
		static void DisplayInt();
		static void DisplayFloat();
		static void DispalyDouble();
};

#endif