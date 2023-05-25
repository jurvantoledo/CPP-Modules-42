#include "../include/Array.hpp"

template<typename T>
Array<T>::Array()
{
    this->_array = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    this->_array = new T[n];
    this->_len = n;

    for (unsigned int i = 0; i < this->_len; i++)
    {
        this->_array[i] = T();
    }
}

template<typename T>
Array<T>::Array(const Array &obj)
{
    this->_array = NULL;
    *this = obj;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &obj)
{
    if (this->_array)
    {
        delete[] this->_array;
    }
    this->_len = obj._len;
    this->_array = new T[this->_len];
    for (unsigned int i = 0; i < this->_len; i++)
		this->_array[i] = obj[i];
    return (*this);
}

template<typename T>
Array<T>::~Array()
{
    delete[] this->_array;
}

template<typename T>
T& Array<T>::operator[] (size_t i) const
{
    if (i >= this->_len)
        throw (IndexOutOfBoundsException());
    return(this->_array[i]);
    
}

template<typename T>
unsigned int Array<T>::size(void)
{
    return (this->_len);
}

template<typename T>
const char* Array<T>::IndexOutOfBoundsException::what(void) const throw()
{
	return "Index out of bounds";
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