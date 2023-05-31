#ifndef RPN_H
#define RPN_H

#include <string>
#include <exception>
#include <algorithm>
#include <sstream>
#include <stack>

class RPN
{
private:
    RPN();
    RPN(const RPN &c);
    ~RPN();
    RPN & operator = (const RPN &c);
public:
	static int	evaluate(char* _input);
};

#endif