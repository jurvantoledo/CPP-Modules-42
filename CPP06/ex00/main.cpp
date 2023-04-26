#include "ScalarConverter.hpp"

std::string	ScalarConverter::_value = "";
char	ScalarConverter::_char = '\0';
int		ScalarConverter::_int = 0;
long	ScalarConverter::_long = 0;
float	ScalarConverter::_float = 0.0f;
double	ScalarConverter::_double = 0.0;


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Needs only 1 argument" <<std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}