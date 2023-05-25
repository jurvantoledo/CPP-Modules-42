#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	std::cout << "ScalarConverter copy assignment operator is called" << std::endl;
	_char = obj._char;
	_int = obj._int;
	_long = obj._long;
	_float = obj._float;
	_double = obj._double;
	_value = obj._value;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

bool	ScalarConverter::checkChar(std::string val)
{
	int len = val.length();

	for (size_t i = 0; val[i]; i++)
	{
		if (!isdigit(val[i]) && val[len - 1] == 'f')
		{
			if (i != len && i == 'f')
			{
				return (false);
			}
		}
	}
	
	if (val[len - 1] == 'f')
		return (true);
	return (false);
}

int	ScalarConverter::getType()
{
	char	*end;

	// string to long
	std::strtol(_value.c_str(), &end, 10);
	if (*end == '\0')
		return (INT);

	if (_value.length() == 1 && _value[0] >= 0 && _value[0] <= 127 && isprint(_value[0]))
		return (CHAR);

	// string to float
	std::strtof(_value.c_str(), &end);
	if (*end == '\0' || _value.compare("-inff") == 0 || _value.compare("inff") == 0 \
		|| _value.compare("nanf") == 0 || checkChar(_value) == true)
		return (FLOAT);

	// string to double
	std::strtod(_value.c_str(), &end);
	if (*end == '\0')
		return (DOUBLE);

	return (INVALID);
}

void	ScalarConverter::convert(std::string input)
{
	int	type;

	_value = input;
	type = getType();

	if (type == CHAR)
		ConvertChar();
	else if (type == INT)
		ConvertInt();
	else if (type == FLOAT)
		ConvertFloat();
	else if (type == DOUBLE)
		ConvertDouble();
	if (type == INVALID)
	{
		std::cout << "Invalid" << std::endl;
		return ;
	}
	printTypes();
}

void	ScalarConverter::ConvertChar()
{
	_char = static_cast<char>(_value[0]);
	_int = static_cast<int>(_char);
	_long = static_cast<long>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	ScalarConverter::ConvertInt()
{
	_int = static_cast<int>(atoi(_value.c_str()));
	_long = static_cast<long>(atol(_value.c_str()));
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void	ScalarConverter::ConvertFloat()
{
	_float = static_cast<float>(atof(_value.c_str()));
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_long = static_cast<long>(_float);
	_double = static_cast<double>(_float);
}

void	ScalarConverter::ConvertDouble()
{
	_double = static_cast<double>(atof(_value.c_str()));
	_float = static_cast<float>(_double);
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_long = static_cast<long>(_double);
}

void	ScalarConverter::DisplayChar()
{
    std::cout << "char: ";
    if (_int < 0 || _int > 127)
        std::cout << "impossible";
    else if (isprint(_char))
        std::cout << _char;
    else
        std::cout << "non displayable";
    std::cout << std::endl;
}

void ScalarConverter::DisplayInt()
{
	std::cout << "int: ";
	if (_long > INT_MAX || _long < INT_MIN)
	{
		std::cout << "impossible" << std::endl;
	}
	else
		std::cout << _int << std::endl;
}

void ScalarConverter::DisplayFloat()
{
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1);
	if (getType() == INVALID)
		std::cout << "NaN"; 
	else
		std::cout << _float;
	std::cout << "f";
	std::cout << std::endl;
}

void ScalarConverter::DispalyDouble()
{
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1);
	if (getType() == INVALID)
		std::cout << "NaN"; 
	else
		std::cout << _double;
	std::cout << std::endl;
}

void	ScalarConverter::printTypes()
{
	DisplayChar();
	DisplayInt();
	DisplayFloat();
	DispalyDouble();
}
