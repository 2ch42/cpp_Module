#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>


class Bureaucrat
{
    private:
        const   std::string name;
        int     grade;  // 1 ~ 150 possible
    public:
        Bureaucrat();
        Bureaucrat(const std::string name);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& bereaucrat);
        Bureaucrat& operator=(const Bureaucrat& bereaucrat);
        ~Bureaucrat();
        const std::string& getName() const;
        const int& getGrade() const;
        void    grade_up(); // grade number size decrease
        void    grade_down(); // grade number size increase
        class GradeTooHighException;
        class GradeTooLowException;
};

#endif