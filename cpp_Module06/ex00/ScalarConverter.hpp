#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& sc);
        ScalarConverter& operator=(const ScalarConverter& sc);
        ~ScalarConverter();
    public:
        static void convert(std::string raw);
};

typedef enum e_type
{
    _char = 1,
    _int = 2,
    _float = 3,
    _double = 4,
    _no_type = 5
}   t_type;

typedef struct s_converter
{
    t_type  type;
    int     impos;
    int     non_d;
    int     i;
    char    c;
    float   f;
    double  d;
}   t_converter;

#endif