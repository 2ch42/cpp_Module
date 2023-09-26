#include <iostream>
#include "Zombie.hpp"

int main()
{
	std::cout << "*****FIVE ZOMBIE CREATION*****" << std::endl;
	Zombie *five_zombie = zombieHorde(5, "five zombie");
	for (int i = 0; i < 5; i++)
	{
		(five_zombie + i)->announce();
	}
	delete[] five_zombie;
	std::cout << "*****TEN ZOMBIE CREATION*****" << std::endl;
	Zombie *ten_zombie = zombieHorde(10, "ten zombie");
	for (int i = 0; i < 10; i++)
	{
		(ten_zombie + i)->announce();
	}
	delete[] ten_zombie;
	return (0);
}
