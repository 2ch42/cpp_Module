#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat test1 = Bureaucrat("test1", 10);
    Bureaucrat test2 = Bureaucrat("test2", 20);
    Form    form = Form("form", 15, 20);

    std::cout << test1 << "\n" << test2 << "\n" << form << std::endl;

    test2.signForm(form);
    test1.signForm(form);

    return (0);
}