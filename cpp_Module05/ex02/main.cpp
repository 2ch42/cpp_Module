#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat test1_1("test1_1", 145);
    Bureaucrat test1_2("test1_2", 137);
    Bureaucrat test2_1("test2_1", 72);
    Bureaucrat test2_2("test2_2", 45);
    Bureaucrat test3_1("test3_1", 25);
    Bureaucrat test3_2("test3_2", 5);

    ShrubberyCreationForm form1("form1");
    RobotomyRequestForm form2("form2");
    PresidentialPardonForm form3("form3");

    std::cout << "Not signed test" << std::endl;
    test1_2.executeForm(form1);
    test2_2.executeForm(form2);
    test3_2.executeForm(form3);
    
    std::cout << "--------------------" << std::endl;
    test1_1.signForm(form1);
    test2_1.signForm(form2);
    test3_1.signForm(form3);
    std::cout << "Level filtering(fail) test" << std::endl;
    test1_1.executeForm(form1);
    test2_1.executeForm(form2);
    test3_1.executeForm(form3);

    std::cout << "--------------------" << std::endl;
    std::cout << "Level filtering(success) test" << std::endl;
    test1_2.executeForm(form1);
    test2_2.executeForm(form2);
    test3_2.executeForm(form3);

    return (0);
}