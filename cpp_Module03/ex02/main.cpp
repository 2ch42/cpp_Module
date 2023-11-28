#include <iostream>
#include "FragTrap.hpp"

///*
int main() // test1
{
    std::cout << "-----FRAGTRAP DECLARE-----" << std::endl;
    FragTrap a("No.1-1");
    FragTrap b("No.1-2");
    std::cout << "-----SCAVTRAP DECLARE-----" << std::endl;
    ScavTrap c("No.1-3");
    std::cout << "-----CLAPTRAP DECLARE-----" << std::endl;
    ClapTrap d("No.1-4");
    std::cout << "\n";

    std::cout << "-----FRAGTRAP USAGE-----" << std::endl;
    a.highFiveGuys();
    b.highFiveGuys();
    a.attack("test1");
    b.attack("test1");
    c.attack("test1");
    d.attack("test1");
}
//*/

/*
int main() // test2
{
    FragTrap a("No.2-1");
    FragTrap b("No.2-2");

    for (int i = 0; i < 6; i++)
    {
        std::cout << i + 1 << " : ";
        a.takeDamage(20);
    }

    for (int i = 0; i < 101; i++)
    {
        std::cout << i + 1 << " : ";
        b.beRepaired(10);
    }
    return (0);
}
*/