#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& intern)
{
    (void) intern;
}

Intern& Intern::operator=(const Intern& intern)
{
    (void) intern;
    return (*this);
}

Intern::~Intern()
{
}

int check_name(std::string name)
{
    if (name == "shrubbery creation")
        return (1);
    if (name == "robotomy request")
        return (2);
    if (name == "presidential pardon")
        return (3);
    else
        return (0);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm* form;
    switch(check_name(name))
    {
        case 1:
            form = new ShrubberyCreationForm(target);
            break;
        case 2:
            form = new RobotomyRequestForm(target);
            break;
        case 3:
            form = new PresidentialPardonForm(target);
            break;
        default:
            std::cerr << "The name given doesn't exist." << std::endl;
            return (NULL);
    }
    std::cout << "Intern creates " << name << std::endl;
    return (form);
}