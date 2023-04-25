#include "../include/Types.hpp"

Types::Types(const std::string &value) : _value(value)
{
    std::cout << "Default constructor is called" << std::endl;
}

Types::Types(const Types &obj)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = obj;
}

Types& Types::operator=(const Types &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    (void)obj;
    return (*this);
}

Types::~Types()
{
    std::cout << "Destructor is called" << std::endl;
}

int Types::getTypes()
{
    char *end;
    if (this->_value.length() == 1 && isalpha(_value[0]))
        return (CHAR);

    // string to long
    std::strtol(_value.c_str(), &end, 10);
    if (*end == '\0')
        return (INT);
    
    // string to float
    std::strtof(_value.c_str(), &end);
    if (*end == '\0')
        return (FLOAT);
    
    // string to double
    std::strtod(_value.c_str(), &end);
    if (*end == '\0')
        return (DOUBLE);
    return (INVALID);
}

void Types::ToChar()
{
    this->cValue = static_cast<char>(this->_value[0]);
    this->iValue = static_cast<long int>(cValue);
    this->fValue = static_cast<float>(fValue);
    this->dValue = static_cast<double>(dValue);
}

void Types::ToInt()
{
    this->iValue = static_cast<long int>(atol(this->_value.c_str()));
    this->cValue = static_cast<char>(iValue);
    this->fValue = static_cast<float>(iValue);
    this->dValue = static_cast<double>(iValue);
}

void Types::ToFloat()
{
    this->fValue = static_cast<float>(atof(this->_value.c_str()));

    this->cValue = static_cast<char>(fValue);
    this->iValue = static_cast<long int>(fValue);
    this->dValue = static_cast<double>(fValue);
}

void Types::ToDouble()
{
    this->dValue = static_cast<double>(atof(this->_value.c_str()));

    this->cValue = static_cast<char>(dValue);
    this->iValue = static_cast<long int>(dValue);
    this->fValue = static_cast<float>(dValue);
}

void Types::DisplayChar()
{
    if (isprint(this->cValue) && (this->iValue <= INT_MAX && this->iValue >= INT_MIN))
        std::cout << this->cValue << std::endl;
    else if (isascii(this->cValue) && (this->iValue <= INT_MAX && this->iValue >= INT_MIN))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void Types::DisplayInt()
{
    if (this->iValue <= INT_MAX && this->iValue >= INT_MIN)
        std::cout << this->iValue << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void Types::DisplayFloat()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    std::cout << this->fValue << "f" << std::endl;
}

void Types::DisplayDouble()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    std::cout << this->dValue << std::endl;
}

void Types::DisplayVars()
{
    DisplayChar();
    DisplayInt();
    DisplayFloat();
    DisplayDouble();
}

void Types::ConvertTo()
{
    int type = getTypes();

    switch (type)
    {
        case CHAR:
            ToChar();
            break;
        case INT:
            ToInt();
            break;
        case FLOAT:
            ToFloat();
            break;
        case DOUBLE:
            ToDouble();
            break;
        default:
            break;
    }
}