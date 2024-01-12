#include <iostream>
#include <stdexcept>
#include "RPN.hpp"

void    simple_valid(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!(std::isdigit(str[i])|| is_oper(str[i]) || str[i] == ' '))
            throw(std::runtime_error("Error"));
    }
}

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
            throw (std::runtime_error("Error"));
        simple_valid(argv[1]);
        RPN rpn;
        rpn.calculate(argv[1]);
        std::cout << rpn.get_result() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}