#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)toupper(str[j]);
	}
	std::cout << std::endl;
}