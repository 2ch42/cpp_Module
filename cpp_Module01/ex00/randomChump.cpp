#include <iostream>
#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie rdzombie = Zombie(name);
	rdzombie.announce();
}
