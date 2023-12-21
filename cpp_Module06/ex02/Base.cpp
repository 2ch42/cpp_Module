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
    if (rand() % 3 == 1)
    {
        Base *base = new A();
        return base;
    }
    else if (rand() % 3 == 2)
    {
        Base *base = new B();
        return base;
    }
    else
    {
        Base *base = new C();
        return base;
    }
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Actual type : A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Actual type : B" << std::endl;
    else
        std::cout << "Actual type : C" << std::endl;
}

/*void    identify(Base& p)
{

}

*/