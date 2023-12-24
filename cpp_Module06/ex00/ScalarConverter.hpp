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

typedef struct s_converter
{
    int dot;
    int sign;
    int f_num;
    int only_digit;
    char    char_val;
    int     int_val;
    float   float_val;
    double  double_val;
    int     char_exc;
    int     int_exc;
    float   float_exc;
    double  double_exc;
    t_type  type;
}   t_converter;

typedef enum e_type
{
    _char = 1,
    _int = 2,
    _float = 3,
    _double = 4,
    _special_d = 5,
    _special_f = 6,
    _impos = 6,
}   t_type;

#endif