#include <iostream>
#include "Zombie.hpp"

int main()
{
	std::cout << "*****Allocate on stack*****" << std::endl;
	randomChump("RANDOMCHUMPZOMBIE");
	std::cout << "*****Allocate on heap *****" << std::endl;
	Zombie *newzombie = newZombie("NEWZOMBIEZOMBIE");
	newzombie->announce();
	delete newzombie;
}
