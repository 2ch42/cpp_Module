#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "This should not happen..." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& sc)
{
    std::cout << "This should not happen..." << std::endl;
    (void) sc;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& sc)
{
    std::cout << "This should not happen..." << std::endl;
    (void) sc;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "This should not happen..." << std::endl;
}

typedef enum e_type
{
    c = 1,
    i = 2,
    f = 3,
    d = 4
}   t_type;

t_type getType(std::string raw)
{
    if (raw.)
}

void    ScalarConverter::convert(std::string raw)
{

}