#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if (this != &bureaucrat)
    {
        this->grade = bureaucrat.getGrade();
    }
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::grade_up()
{
    try
    {
        if (this->grade <= 1)
            throw GradeTooHighException();
        this->grade--;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::grade_down()
{
    try
    {
        if (this->grade >= 150)
            throw GradeTooLowException();
        this->grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("BUREAUCRAT GRADE TOO HIGH EXCEPTION!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("BUREAUCRAT GRADE TOO LOW EXCEPTION!");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}

void    Bureaucrat::signForm(AForm& form) // ex01
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " couldn't sign " \
        << form.getName() << " because " << e.what() << std::endl;
    }
}