#include "../include/Serializer.hpp"

/**
 * @brief reinterpret_cast 
 * reinterpret_cast converts one pointer to another without changing the address, 
 * or converts between pointers and their numerical (integer) values.
 */

int main()
{
    Data data = {.name = "Naam", .number = 400};
    std::cout << std::endl;
    std::cout << "------------ DATA -----------" << std::endl;
	std::cout << "Name: " << data.name << std::endl;
    std::cout << "Number: " << data.number << std::endl;
    std::cout << "address: " << &data << std::endl;
    std::cout << std::endl;

	uintptr_t	serialized = Serializer::serialize(&data);
	std::cout << "serialized   : " << serialized << " ( 0x" << std::hex << serialized << " )" << std::endl;

	Data*		deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized : " << deserialized << std::endl;
    return (0);
}