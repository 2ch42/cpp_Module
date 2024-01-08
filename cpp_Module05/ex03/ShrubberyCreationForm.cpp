#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& sform) : AForm(sform.getName(), 145, 137), target(sform.getTarget())
{    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& sform)
{
    std::cout << "Cannot use Copy Assignment Operator by " << sform.getName() << std::endl;
    return (*(this));
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137), target(target)
{  
}

const std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (this->get_b_signed() == false)
        throw UnsignedException();
    else if (executor.getGrade() > this->get_e_grade())
        throw GradeTooLowException();
    std::string new_file = executor.getName();
    new_file += "_shrubbery";
    std::string text;
    text += "      /\\      \n";
    text += "     /\\*\\     \n";
    text += "    /\\O\\*\\    \n";
    text += "   /*/\\/\\/\\   \n";
    text += "  /\\O\\/\\*\\/\\  \n";
    text += " /\\*\\/\\*\\/\\/\\ \n";
    text += "/\\O\\/\\/*/\\/O/\\ \n";
    text += "      ||      \n";
    text += "      ||      \n";
    text += "      ||      \n";
    std::ofstream out(new_file);
    if (out.is_open())
        out << text;
    else
        std::cout << "File Open Error!" << std::endl;
}