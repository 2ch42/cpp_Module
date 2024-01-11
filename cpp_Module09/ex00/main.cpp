#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
            throw(std::runtime_error("Error: could not open file."));
        BitcoinExchange be;
        std::ifstream _original_f("data.csv");
        std::ifstream _new_f(argv[1]);
        be.fill_original(_original_f);
        be.fill_new(_new_f);
        be.print_result();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
   
    return (0);
}