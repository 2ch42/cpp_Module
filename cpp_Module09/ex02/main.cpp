#include "PmergeMe.hpp"
#include <iostream>

void    check_arg(int argc, char *argv[])
{
    if (argc < 2)
        throw (std::runtime_error("Error"));
    for(int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);
        for(unsigned int j = 0; j < str.length(); j++)
        {
            if (!std::isdigit(argv[i][j]))
                throw(std::runtime_error("Error"));
        }
    }
}

void    print_before(int argc, char *argv[])
{
    std::cout << "Before:  ";
    for(int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    try
    {
        check_arg(argc, argv);
        PmergeMe pmm;
        print_before(argc, argv);
        pmm.oper_deq(argc, argv);
        pmm.oper_vector(argc, argv);
        pmm.print_vector();
        //pmm.print_deq();
        pmm.print_time();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}