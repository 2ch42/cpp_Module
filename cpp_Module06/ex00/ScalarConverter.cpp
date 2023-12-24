#include <string>
#include "ScalarConverter.hpp"

void    init_converter(t_converter& converter)
{
    converter.dot = 0;
    converter.sign = 0;
    converter.f_num = 0;
    converter.only_digit = 1;
    converter.type = _impos;
    converter.char_val = 0;
    converter.int_val = 0;
    converter.float_val = 0;
    converter.double_val = 0;
    converter.char_exc = 0;
    converter.int_exc = 0;
    converter.float_exc = 0;
    converter.double_exc = 0;
}

void    get_type(std::string raw, t_converter& converter)
{
    if (raw == "nan" || raw == "+inf" || raw == "-inf")
    {
        converter.type = _special_d;
        return ;
    }
    if (raw == "nanf" || raw == "+inff" || raw == "-inff")
    {
        converter.type = _special_f;
        return ;
    }
    if (raw.size() == 1)
    {
        converter.type = _char;
        return ;
    }
    for (int i = 0; i < raw.size(); i++)
    {
        if (raw.at(i) == '.')
            converter.dot++;
        else if (raw.size() > 1 && raw.at(0) == '-')
            converter.sign = 1;
        else if (raw.at(i) == 'f')
            converter.f_num++;
        else if (!std::isdigit(raw.at(i)))
            converter.only_digit = 0;
    }
    if (converter.dot > 1)
    {
        converter.type = _impos;
        return ;
    }
    if (converter.only_digit == 0 && converter.dot == 0 && converter.f_num == 0)
    {
        converter.type = _int;
        return ;
    }
    if (converter.only_digit == 0 && converter.dot == 1 && converter.f_num == 0)
    {
        converter.type = _double;
        return ;
    }
    if (converter.only_digit == 0 && converter.dot == 1 && converter.f_num == 1
        && raw.at(raw.size() - 1) == 'f')
    {
        converter.type = _float;
        return ;
    }
}

void    ex_convert(std::string raw, t_converter& converter)
{
    if (converter.type == _impos)
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: impossible\n"
        << "double: impossible\n" << std::endl; 
    }
    if (converter.type == _special_d)
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: " << raw << "f\n"
        << "double: " << raw << std::endl;
    }
    if (converter.type == _special_f)
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: " << raw
        << "double: " << raw.substr(0, raw.size() - 1) << std::endl;
    }
    if (converter.type == _int)
    {
        converter.int_val = static_cast<int>(std::strtod(raw.c_str(), NULL));
        if (converter.int_val != std::strtod(raw.c_str(), NULL))
            converter.int_exc = 1;
        converter.char_val = static_cast<char>(converter.int_val);
        if (converter.char_val != converter.int_val)
            converter.char_exc = 1;
        
    }
    if (converter.type == _char)
    {
        converter.char_val = raw.at(0);
        if (!(converter.char_val >= 33 && converter.char_val <= 126))
            converter.char_exc == 1;
        converter.int_val = static_cast<int>(converter.char_val);
        converter.float_val = static_cast<float>(converter.char_val);
        converter.double_val = static_cast<double>(converter.char_val);
    }
}

void    print_r(std::string raw, t_converter& converter)
{
}

void    ScalarConverter::convert(std::string raw)
{
    t_converter converter;

    init_converter(converter);
    get_type(raw, converter);
    ex_convert(raw, converter);
    if (converter.type != _impos && converter.type != _special_d && converter.type != _special_f)
        print_r(raw, converter);
}