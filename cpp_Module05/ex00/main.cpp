#include "Bureaucrat.hpp"

/*
int main()
{
    Bureaucrat a = Bureaucrat("test1", 150);
    Bureaucrat b = Bureaucrat("test2", 1);
    Bureaucrat c = Bureaucrat("test3", 151);
    Bureaucrat d = Bureaucrat("test4", 0);

    std::cout << "Grade Check : " << a << std::endl;
    std::cout << "Grade Check : " << b << std::endl;
    a.grade_down();
    b.grade_up();
    b.grade_down();
    std::cout << "Grade Check " << b << std::endl;
    return (0);
}
*/

int main()
{
    try
    {
        Bureaucrat test1 = Bureaucrat("test1", 150);
        Bureaucrat test2 = Bureaucrat("test2", 1);
        Bureaucrat test3 = Bureaucrat("test3", 151); // 
        Bureaucrat test4 = Bureaucrat("test4", 0); // 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------" << std::endl;
    try
    {
        Bureaucrat test1 = Bureaucrat("test1", 150);
        Bureaucrat test2 = Bureaucrat("test2", 1);
        Bureaucrat test3 = Bureaucrat("test3", 0); // reversed.
        Bureaucrat test4 = Bureaucrat("test4", 151); //
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------" << std::endl;
    try
    {
        Bureaucrat test1 = Bureaucrat("test1", 150);
        Bureaucrat test2 = Bureaucrat("test2", 1);
        std::cout << test1 << std::endl;
        test1.grade_down();
        std::cout << test1 << std::endl;
        test1.grade_up();
        std::cout << test1 << std::endl;
        std::cout << test2 << std::endl;
        test2.grade_up();
        std::cout << test2 << std::endl;
        test2.grade_down();
        std::cout << test2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}