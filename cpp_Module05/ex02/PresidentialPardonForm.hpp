#ifndef PRESIDENTIALPARDOMFORM_HPP
# define PRESIDENTIALPARDOMFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& pform);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& pform);
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        const std::string getTarget() const;
        void    execute(Bureaucrat const& executor) const;
};

#endif