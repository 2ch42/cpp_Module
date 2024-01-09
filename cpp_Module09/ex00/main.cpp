#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

void    argc_checker(int argc, char *argv[])
{
    if (argc != 2)
        throw(std::runtime_error("Error: could not open file."));
}

int main(int argc, char *argv[])
{
    try
    {
        argc_checker(argc, argv);
        BitcoinExchange be;
        std::ifstream _original_f("data.csv");
        std::ifstream _new_f(argv[1]);
        be.fill_original(_original_f);
        be.fill_original(_new_f);
        //[...]
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
   
    return (0);
}