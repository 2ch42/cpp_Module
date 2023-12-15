#include "Form.hpp"

Form::Form() : name("Default"), b_signed(false), s_grade(1), e_grade(1)
{
}

Form::Form(const Form& form) : name(form.getName()), b_signed(false), s_grade(form.get_s_grade()), e_grade(form.get_e_grade())
{
}

Form& Form::operator=(const Form& form)
{
    if (this != &form)
    {
        b_signed = false;
    }
    return (*this);
}

Form::~Form()
{
}

Form::Form(std::string name, const int s_grade, const int e_grade) : name(name), b_signed(false), s_grade(s_grade), e_grade(e_grade)
{
}

const std::string Form::getName() const
{
    return (this->name);
}

bool Form::get_b_signed() const
{
    return (this->b_signed);
}

int Form::get_s_grade() const
{
    return (this->s_grade);
}

int Form::get_e_grade() const
{
    return (this->e_grade);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("FORM GRADE TOO HIGH EXCEPTION!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("FORM GRADE TOO LOW EXCEPTION!");
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if (this->s_grade < bureaucrat.getGrade())
        throw GradeTooLowException();
    this->b_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Name : " << form.getName() << ", bool signed : " \
    << form.get_b_signed() << ", sign grade : " << form.get_s_grade() \
    << ", execute grade : " << form.get_e_grade();
    return (out);
}