#include <iostream>
#include "ScavTrap.hpp"

///*
int main() // test1
{
    std::cout << "-----SCAVTRAP DECLARE-----" << std::endl;
    ScavTrap a("No.1-1");
    ScavTrap b("No.1-2");
    std::cout << "-----CLAPTRAP DECLARE-----" << std::endl;
    ClapTrap c("NO.1-3");
    std::cout << "\n";

    std::cout << "-----SCAVTRAP USAGE-----" << std::endl;
    a.guardGate();
    b.guardGate();
    a.attack("test1");
    b.attack("test1");
    std::cout << "-----CLAPTRAP USAGE-----" << std::endl;
    c.attack("test1");
}
//*/

/*
int main() // test2
{
    ScavTrap a("No.2-1");
    ScavTrap b("No.2-2");

    for (int i = 0; i < 6; i++)
    {
        std::cout << i + 1 << " : ";
        a.takeDamage(10);
    }

    for (int i = 0; i < 51; i++)
    {
        std::cout << i + 1 << " : ";
        b.beRepaired(10);
    }
    return (0);
}
*/