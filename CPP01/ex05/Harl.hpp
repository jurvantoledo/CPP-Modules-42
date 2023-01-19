#ifndef HARL_H

#define HARL_H
#include <iostream>

class Harl
{
    public:
        Harl(/* args */);
        ~Harl();
        void complain(std::string level);

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif