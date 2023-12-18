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

void    to_char(char *argv)
{
    std::string raw(argv);
    if (raw.size() == 1 && std::isalpha(raw.at(0)))
    {
        std::cout << raw.at(0) << std::endl;
        return ;
    }
    for(int i = 0; i < raw.size(); i++)
    {
        if (!(isdigit(raw.at(i))))
        {
            std::cout << "impossible" << std::endl;
            return ;
        }
    }
    if (std::atoi(argv) != std::atoll(argv))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (std::atoi(argv) > 127 || std::atoi(argv) < 0)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::cout << "\'" << static_cast<char>(std::atoi(argv)) << "\'" << std::endl;
}

void    to_int(char *argv)
{
    std::string raw(argv);
    int dot = 0;
    if (raw.at(0) != '-' && !std::isdigit(raw.at(0)))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    for (int i = 1; i < raw.size() - 1; i++)
    {
        if (raw.at(i) == '.')
            dot++;
        if (!std::isdigit(raw.at(i) && raw.at(i) != '.'))
        {
            std::cout << "impossible" << std::endl;
            return ;
        }
    }
    if (dot > 1)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (raw.at(raw.size() - 1) != 'f' && !(isdigit(raw.at(raw.size() - 1))))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (std::atoi(argv) != std::atoll(argv))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::cout << std::atoi(argv) << std::endl;
}

int fd_common(char *argv)
{
    std::string raw(argv);
    if (raw.size() == 3)
    {
        if (std::toupper(raw.at(0)) == 'N' \
        && std::toupper(raw.at(1)) == 'A' && std::toupper(raw.at(2)) == 'N')
        {
            std::cout << "nan" << std::endl;
            return (1);
        }
    }
    if (raw.size() == 4)
    {
        if (raw.at(0) == 
    }
}

void    to_float(char *argv)
{
    if (fd_common(argv))
    {
        if ((std::atof(argv) == (std::atof(argv) + 1)))
        {
            std::cout << "impossible" << std::endl;
        }
        std::cout << "f" << std::endl;
    }
}

void    to_double(char *argv)
{
    if (fd_common(argv))
}

void    ScalarConverter::convert(char *argv)
{
    std::cout << "char: " << std::endl;
    to_char(argv);
    std::cout << "int: " << std::endl;
    to_int(argv);
    std::cout << "float: " << std::endl;
    to_float(argv);
    std::cout << "double: " << std::endl;
    to_double(argv);
    std::cout << "\n";
}