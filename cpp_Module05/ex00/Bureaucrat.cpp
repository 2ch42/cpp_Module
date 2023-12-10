#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name) : name(name), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    try
    {
        this->grade = grade;
        if (this->grade > 150)
            throw (GradeTooHighException);
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& bereaucrat) : name(bereaucrat.name), grade(bereaucrat.grade)
{
}