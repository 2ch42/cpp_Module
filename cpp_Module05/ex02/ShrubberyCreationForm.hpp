#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string& target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& sform);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& sform);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string& target);
};

#endif