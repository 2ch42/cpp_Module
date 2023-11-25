#include <iostream>
#include "ClapTrap.hpp"


int main() // test1
{
    ClapTrap test("NO.1");
    for (int i = 0; i < 6; i++)
    {
        std::cout << i + 1 << " : ";
        test.takeDamage(2);
    }
    return (0);
}


/*
int main() // test2
{
    ClapTrap test("No.2");
    for(int i = 0; i < 11; i++)
    {
        std::cout << i + 1 << " : ";
        test.attack("sandbag");
    }
    return (0);
}
*/

/*
int main() //test3
{
    ClapTrap test("No.3");
    for(int i = 0; i < 11; i++)
    {
        std::cout << i + 1 << " : ";
        test.beRepaired(10);
    }
    return (0);
}
*/