#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    Intern someRandomIntern;
    AForm* rrf1;
    AForm* rrf2;
    AForm* rrf3;
    AForm* rrf4;

    rrf1 = someRandomIntern.makeForm("shrubbery creation", "A");
    rrf2 = someRandomIntern.makeForm("robotomy request", "B");
    rrf3 = someRandomIntern.makeForm("presidential pardon", "C");
    rrf4 = someRandomIntern.makeForm("some random name", "D");
    delete rrf1;
    delete rrf2;
    delete rrf3;
    delete rrf4;
    return (0);
}