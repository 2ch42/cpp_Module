#include "AForm.hpp"

AForm::AForm() : name("Default"), b_signed(false), s_grade(1), e_grade(1)
{
}

AForm::AForm(const AForm& form) : name(form.getName()), b_signed(false), s_grade(form.get_s_grade()), e_grade(form.get_e_grade())
{
}

AForm& AForm::operator=(const AForm& form)
{
    if (this != &form)
    {
        b_signed = false;
    }
    return (*this);
}

AForm::~AForm()
{
}

AForm::AForm(std::string name, const int s_grade, const int e_grade) : name(name), b_signed(false), s_grade(s_grade), e_grade(e_grade)
{
}

const std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::get_b_signed() const
{
    return (this->b_signed);
}

int AForm::get_s_grade() const
{
    return (this->s_grade);
}

int AForm::get_e_grade() const
{
    return (this->e_grade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("FORM GRADE TOO HIGH EXCEPTION!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("FORM GRADE TOO LOW EXCEPTION!");
}

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (this->s_grade < bureaucrat.getGrade())
        throw GradeTooLowException();
    this->b_signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Name : " << form.getName() << ", bool signed : " \
    << form.get_b_signed() << ", sign grade : " << form.get_s_grade() \
    << ", execute grade : " << form.get_e_grade();
    return (out);
}