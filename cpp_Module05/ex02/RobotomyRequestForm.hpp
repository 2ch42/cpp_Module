#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& rform);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rform);
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        const std::string getTarget() const;
        void    execute(Bureaucrat const& executor) const;
};

#endif