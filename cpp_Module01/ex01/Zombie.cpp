#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default constructor called." << std::endl;
}

Zombie::Zombie(std::string name)
{
	 this->name = name;
	 std::cout << "Constructor with parameter called." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set(std::string name)
{
	this->name = name;
	std::cout << "function set activated." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is destoryed." << std::endl;
}
