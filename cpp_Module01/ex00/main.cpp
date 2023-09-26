#include <iostream>
#include "Zombie.hpp"

int main()
{
	std::cout << "*****ALLOCATE ON STACK*****" << std::endl;
	randomChump("randomchump zombie");
	std::cout << "*****ALLOCATE ON HEAP *****" << std::endl;
	Zombie *newzombie = newZombie("newzombie zombie");
	newzombie->announce();
	delete newzombie;
	return (0);
}
