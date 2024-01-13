#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>

void    check_arg(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);

    }
}

int main(int argc, char *argv[])
{
    try
    {
        check_arg(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}