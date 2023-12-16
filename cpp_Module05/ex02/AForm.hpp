#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    b_signed;
        const int   s_grade; // sign grade
        const int   e_grade; // execute grade
    public:
        AForm();
        AForm(std::string name, const int s_grade, const int e_grade);
        AForm(const AForm& form);
        AForm& operator=(const AForm& form);
        virtual ~AForm();
        const std::string getName() const;
        bool  get_b_signed() const;
        int   get_s_grade() const;
        int   get_e_grade() const;
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

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif