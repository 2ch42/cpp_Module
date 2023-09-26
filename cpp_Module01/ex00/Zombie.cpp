#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	 this->name = name;
	 std::cout << "Constructor called." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destoryed." << std::endl;
}
