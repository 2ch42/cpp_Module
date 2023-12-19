#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
    }
    std::string s(argv[1]);
    ScalarConverter::convert(s);
    //ScalarConverter A;
    return (0);
}