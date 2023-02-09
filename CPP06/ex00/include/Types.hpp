#ifndef TYPES_H

#define TYPES_H
#include <iostream>

class Types
{
    private:
        std::string _value;
        char cValue;
        int iValue;
        float fValue;
        double dValue;

        
    public:
        Types(const std::string &value);
        Types(const Types &obj);
        Types &operator=(const Types &obj);
        ~Types();

        void getTypes();
};


#endif