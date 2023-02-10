#ifndef DATA_H

#define DATA_H
#include <iostream>
#include <cstdint>

class Data
{
    private:
        int _value;
    public:
        Data();
        Data(const Data &obj);
        Data &operator=(const Data &obj);
        ~Data();
        
        void test();
};


#endif