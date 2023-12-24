#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base *generate(void)
{
    static int seed = 0;
    if (seed == 0)
    {
       seed = time(NULL);
       srand(seed);
    }
    Base *base;
    switch (rand() % 3)
    {
        case 1:
            base = new A();
            break ;
        case 2:
            base = new B();
            break;
        default:
            base = new C();
    }
    return base;
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Actual type : A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Actual type : B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Actual type : C" << std::endl;
    else
        std::cerr << "Cannot find actual type..." << std::endl;
}

void    identify(Base& p)
{
    try
    {
        p = dynamic_cast<A& >(p);
        std::cout << "Actual type : A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            p = dynamic_cast<B& >(p);
            std::cout << "Actual type : B" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "Actual type : C" << std::endl;
        }
    }
}