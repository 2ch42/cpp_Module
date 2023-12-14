#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool    b_signed;
        const int   s_grade; // sign grade
        const int   e_grade; // execute grade
    public:
        Form();
        Form(const Form& form);
        Form& operator=(const Form& form);
        ~Form();
        const std::string getName() const;
        bool  get_b_signed() const;
        const int   get_s_grade() const;
        const int   get_e_grade() const;
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            const char* what() const throw();
        };
        void    beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif