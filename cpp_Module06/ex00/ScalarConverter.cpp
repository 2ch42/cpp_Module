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

const char* ScalarConverter::Impossible::what() const throw()
{
    return ("impossible");
}

const char* ScalarConverter::Nondisplayable::what() const throw()
{
    return ("Non displayable");
}

t_type getType(std::string raw)
{
    if (raw.size() == 1 && std::isdigit(raw.at(0)))
        return (_char);
    if (raw == "nanf" || raw == "+inff" || raw == "-inff")
        return (_float);
    if (raw == "nan" || raw == "+inf" || raw == "-inf")
        return (_double);
    int dot = 0;
    int f_num = 0;
    for(int i = 0; i < raw.size(); i++)
    {
        if (raw.at(i) == '.')
            dot++;
        if (raw.at(i) == 'f')
            f_num++;
        if (!std::isdigit(raw.at(i)) && raw.at(i) != 'f')
            return (_impos);
    }
    if (dot > 1 || f_num > 1)
        return (_impos);
    if (f_num == 1 && raw.at(raw.size() - 1) == 'f')
        return (_float);
    if (f_num == 0 && dot > 0)
        return (_double);
    if (dot == 0 && f_num == 0)
        return (_int);
    std::cout << "Not Filtered in getType : " << raw << std::endl;
    return (_impos);
}

void    ScalarConverter::convert(std::string raw)
{
    t_type strtype = getType(raw);
    if (strtype == _impos)
        throw Impossible();
    if (strtype == _nondp)
        throw Nondisplayable();
    if (strtype == _int)
    {
        
    }
        
}