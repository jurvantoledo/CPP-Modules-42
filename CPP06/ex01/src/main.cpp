#include "../include/Data.hpp"

uintptr_t serialize(Data* ptr)
{
    uintptr_t new_ptr = reinterpret_cast<uintptr_t>(ptr);
    return (new_ptr);
}

Data* deserialize(uintptr_t raw)
{
    Data* new_prt = reinterpret_cast<Data*>(raw);
    return (new_prt);
}

int main()
{
    Data data;
    Data *ptr = &data;

    uintptr_t serialized = serialize(ptr);
    Data* deserialized = deserialize(serialized);

    std::cout << std::endl;
    std::cout << "TEST Serialized" << std::endl;
    std::cout << "uintptr ptr: " << &serialized << std::endl;
    std::cout << "uintptr: " << serialized << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "TEST Desirialized" << std::endl;
    std::cout << &deserialized << std::endl;
    std::cout << deserialized << std::endl;
    deserialized->test();
    std::cout << std::endl;
    
    return (0);
}