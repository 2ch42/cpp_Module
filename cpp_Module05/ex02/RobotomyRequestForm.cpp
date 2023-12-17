#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rform) : AForm(rform.getName(), 72, 45), target(rform.getTarget())
{    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rform)
{
    std::cout << "Cannot use Copy constructor by " << rform.getName() << std::endl;
    return (*(this));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{  
}

const std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (this->get_b_signed() == false)
        throw UnsignedException();
    else if (executor.getGrade() > this->get_e_grade())
        throw GradeTooLowException();
    std::cout << "DDDDDDD.... Drilling noise...." << std::endl;
    // 50% success or fail
}