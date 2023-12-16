#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const   std::string name;
        int     grade;  // 1 ~ 150 possible
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& bereaucrat);
        Bureaucrat& operator=(const Bureaucrat& bereaucrat);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void    grade_up(); // grade number size decrease
        void    grade_down(); // grade number size increase
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        void    signForm(AForm& form); // ex01
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif