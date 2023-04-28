#include "../include/Array.hpp"

template<typename T>
Array<T>::Array()
{
    this->_array = new T[0];
    std::cout << "Default constructor is called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    this->_array = new T[n];
    std::cout << "Default constructor is called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &obj)
{
    std::cout << "Copy constructor is called" << std::endl;
    this->_array = NULL;
    *this = obj;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    if (this != &obj)
    {
        this->_len = obj.size();
        this->_array = new T[this->_len];
        for (size_t i = 0; i < obj.size(); i++)
			this->_array[i] = obj[i];
    }
    return (*this);
}

template<typename T>
Array<T>::~Array()
{
    delete[] this->_array;
    std::cout << "Destructor is called" << std::endl;
}

template<typename T>
T& Array<T>::operator[] (size_t i) const
{
    if (i >= this->_len)
		throw(IndexOutOfBoundsException());
    return(this->_array[i]);
    
}

template<typename T>
size_t Array<T>::size(void)
{
    return (this->_len);
}

template<typename T>
std::ostream& operator<< (std::ostream &o, const Array<T> &a)
{
    unsigned int len = a.size();
    for (unsigned int i = 0; i < len; i++)
    {
        o << a[i] << std::endl;
    }
    return (o);
}