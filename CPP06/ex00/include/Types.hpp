#ifndef TYPES_H

#define TYPES_H
#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision

class Types
{
    private:
        std::string _value;
        char cValue;
        int iValue;
        float fValue;
        double dValue;

        enum Type {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            INVALID,
        };

    public:
        Types(const std::string &value);
        Types(const Types &obj);
        Types &operator=(const Types &obj);
        ~Types();


        int getTypes();

        // Display
        void DisplayVars();
        void DisplayChar();
        void DisplayInt();
        void DisplayFloat();
        void DisplayDouble();

        // Convert to
        void ToChar();
        void ToInt();
        void ToFloat();
        void ToDouble();
        void ConvertTo();
};

#endif