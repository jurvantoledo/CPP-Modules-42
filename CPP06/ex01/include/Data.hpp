#ifndef DATA_H

#define DATA_H
#include <iostream>
#include <cstdint>

class Data
{
    private:
        
    public:
        Data();
        Data(const Data &obj);
        Data &operator=(const Data &obj);
        ~Data();

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};


#endif