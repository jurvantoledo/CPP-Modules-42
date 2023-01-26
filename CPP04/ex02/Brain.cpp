#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain Constructor is called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Copy Brain Constructor is called" << std::endl;
    *this = obj;
}

Brain& Brain::operator=(const Brain &obj)
{
    std::cout << "Copy assignment operator is called" << std::endl;

    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = obj.ideas[i];
    }
    
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor is called" << std::endl;
}

