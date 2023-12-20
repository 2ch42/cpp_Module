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
        class Impossible : public std::exception
        {
            const char* what() const throw();
        };
        class Nondisplayable : public std::exception
        {
            const char* what() const throw();
        };
};

typedef enum e_type
{
    _char = 1,
    _int = 2,
    _float = 3,
    _double = 4,
    _impos = 5,
    _nondp = 6
}   t_type;

#endif