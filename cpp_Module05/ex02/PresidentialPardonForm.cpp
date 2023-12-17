#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5), target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& pform) : AForm(pform.getName(), 25, 5), target(pform.getTarget())
{    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& pform)
{
    std::cout << "Cannot use Copy constructor by " << pform.getName()  << std::endl;
    return (*(this));
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{  
}

const std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->get_b_signed() == false)
        throw UnsignedException();
    else if (executor.getGrade() > this->get_e_grade())
        throw GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}