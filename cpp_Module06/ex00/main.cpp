#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
    }
    ScalarConverter::convert(argv[1]);
    //ScalarConverter A;
    return (0);
}