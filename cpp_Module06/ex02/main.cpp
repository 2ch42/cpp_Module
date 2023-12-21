#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
    Base *test1 = generate();
    Base *test2 = generate();
    Base *test3 = generate();

    std::cout << "******POINTER******" << std::endl;

    std::cout << "Test1 : ";
    identify(test1);
    std::cout << "Test2 : ";
    identify(test2);
    std::cout << "Test3 : ";
    identify(test3);

    std::cout << "******REFERENCE******" << std::endl;

    std::cout << "Test1 : ";
    identify(&(*test1));
    std::cout << "Test2 : ";
    identify(&(*test2));
    std::cout << "Test3 : ";
    identify(&(*test3));

    delete test1;
    delete test2;
    delete test3;

    return (0);
}