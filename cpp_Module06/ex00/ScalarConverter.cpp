#include <string>
#include <sstream>
#include "ScalarConverter.hpp"

void    init_converter(t_converter& converter)
{
    converter.type = _no_type;
    converter.impos = 0;
    converter.non_d = 0;
    converter.i = 0;
    converter.c = 0;
    converter.f = 0;
    converter.d = 0;
}

void    fill_converter(t_converter& converter, std::string& raw)
{
    std::stringstream ss;

    if (raw == "nan" || raw == "+inf" || raw == "-inf")
    {
        converter.type = _double;
        ss.str(raw);
        ss >> converter.d;
        return ;
    }
    if (raw == "nanf" || raw == "+inff" || raw == "-inff")
    {
        converter.type = _float;
        raw = raw.substr(0, raw.size() - 1);
        ss << raw;
        ss >> converter.f;
        return ;
    }
    if (raw.size() == 1)
    {
        if (!(raw.at(0) >= '0' && raw.at(0) <= '9'))
        {
            converter.type = _char;
            if (!(raw.at(0) >= 33 && raw.at(0) <= 126))
                converter.non_d = 1;
            converter.c = raw.at(0);
            return ;
        }
    }
    ss << raw;
    ss >> converter.i;
    if (ss.eof())
    {
        converter.type = _int;
        if (ss.fail())
            converter.impos = 1;
        return ;
    }
    ss.clear();
    if (raw.at(raw.size() - 1) == 'f')
    {
        std::string temp_str = raw.substr(0, raw.size() - 1);
        ss.str(temp_str);
        ss >> converter.f;
        if (ss.eof())
        {
            converter.type = _float;
            if (ss.fail())
                converter.impos = 1;
            return ;
        }
        converter.type = _no_type;
        return ;
    }
    ss.clear();
    ss.str(raw);
    ss >> converter.d;
    if (ss.eof())
    {
        converter.type = _double;
        if (ss.fail())
            converter.impos = 1;
    }
}

void    run_converter(t_converter& converter, std::string& raw)
{
    if (converter.type == _no_type || converter.impos == 1)
    {
        std::cout << "char: Impossible\n"
            << "int: Impossible\n"
            << "float: Impossible\n"
            << "double: Impossible" << std::endl;
        return ;
    }
    if (converter.type == _char)
    {
        converter.i = static_cast<int>(converter.c);
        converter.f = static_cast<float>(converter.c);
        converter.d = static_cast<double>(converter.c);
        std::cout << "char: ";
        if (converter.non_d == 1)
            std::cout << "Non displayable";
        else
            std::cout << converter.c;
        std::cout << "\nint: " << converter.i
        << "\nfloat: " << converter.f
        << "f \ndouble: " << converter.d << ".0" << std::endl;
        return ;
    }
    if (converter.type == _int)
    {
        converter.c = static_cast<char>(converter.i);
        converter.f = static_cast<float>(converter.i);
        converter.d = static_cast<double>(converter.i);
        std::cout << "char: ";
        if (converter.c != converter.i)
            std::cout << "Impossible";
        else if (!(converter.c >= 33 && converter.c <= 126))
            std::cout << "Non displayable";
        else
            std::cout << converter.c;
        std::cout << "\nint: " << converter.i
        << "\nfloat: " << converter.f
        << "f \ndouble: " << converter.d << std::endl;
        return ;
    }
    if (converter.type == _float)
    {
        int c_excep = 0;
        int i_excep = 0;
        converter.c = static_cast<char>(converter.f);
        converter.i = static_cast<int>(converter.f);
        converter.d = static_cast<double>(converter.f);
        int num;
        std::stringstream ss;
        ss.str(raw);
        ss >> num;
        if (num == converter.i)
        {
            if (converter.c != converter.i)
                c_excep = 1;
        }
        else
        {
            i_excep = 1;
            c_excep = 1;
        }
        std::cout << "char: ";
        if (c_excep)
            std::cout << "Impossible";
        else if (!(converter.c >= 33 && converter.c <= 126))
            std::cout << "Non displayable";
        else
            std::cout << converter.c;
        std::cout << "\nint: ";
        if (i_excep)
            std::cout << "Impossible";
        else
            std::cout << converter.i;
        std::cout << "\nfloat: " << converter.f
            << "f \ndouble: " << converter.d << std::endl;
        return ;
    }
    converter.c = static_cast<char>(converter.d);
    converter.i = static_cast<int>(converter.d);
    converter.f = static_cast<float>(converter.d);
    int c_excep = 0;
    int i_excep = 0;
    int num;
    std::stringstream ss;
    ss.str(raw);
    ss >> num;
    if (num == converter.i)
    {
        if (converter.c != converter.i)
            c_excep = 1;
    }
    else
    {
        i_excep = 1;
        c_excep = 1;
    }
    std::cout << "char: ";
    if (c_excep)
        std::cout << "Impossible";
    else if (!(converter.c >= 33 && converter.c <= 126))
        std::cout << "Non displayable";
    else
        std::cout << converter.c;
    std::cout << "\nint: ";
    if (i_excep)
        std::cout << "Impossible";
    else
        std::cout << converter.i;
    std::cout << "\nfloat: ";
    if (raw == "nan")
        std::cout << converter.f << "f";
    else if (static_cast<double>(converter.f) != converter.d)
        std::cout << "Impossible";
    else
        std::cout << converter.f << "f";
    std::cout << "\ndouble: " << converter.d << std::endl;
}

void    ScalarConverter::convert(std::string raw)
{
    t_converter converter;

    init_converter(converter);
    fill_converter(converter, raw);
    run_converter(converter, raw);
}