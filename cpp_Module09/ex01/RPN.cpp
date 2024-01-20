#include <iostream>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& r) : _stack(r._stack) {}

RPN& RPN::operator=(const RPN& r)
{
    if (this != &r)
    {
        this->_stack = r._stack;
    }
    return (*this);
}

RPN::~RPN() {}

void    RPN::calculate(char *str)
{
    for(int i = 0; str[i]; i++)
    {
        if (std::isdigit(str[i]))
        {
            this->_stack.push(str[i] - 48);
        }
        if (is_oper(str[i]))
        {
            if (this->_stack.size() < 2)
                throw(std::runtime_error("Error"));
            int num1, num2;
            num2 = this->_stack.top();
            this->_stack.pop();
            num1 = this->_stack.top();
            this->_stack.pop();
            if (str[i] == '+')
                this->_stack.push(num1 + num2);
            else if (str[i] == '-')
                this->_stack.push(num1 - num2);
            else if (str[i] == '*')
                this->_stack.push(num1 * num2);
            else
            {
                if (num2 == 0)
                    throw(std::runtime_error("Error"));
                this->_stack.push(num1 / num2);
            }
        }
    }
}

int RPN::get_result()
{
    if (this->_stack.size() != 1)
        throw (std::runtime_error("Error"));
    return (this->_stack.top());
}

int is_oper(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return (1);
    return (0);
}