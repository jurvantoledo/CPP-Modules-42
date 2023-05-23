#ifndef DATA_H

#define DATA_H
#include <iostream>
#include <cstdint>

struct Data
{
	int			number;
	std::string	name;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &obj);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();

    public:
	    static uintptr_t	serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif