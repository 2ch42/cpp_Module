#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        return (0);
    }
    std::string s(argv[1]);
    ScalarConverter::convert(s);
    //ScalarConverter A;
    return (0);
}