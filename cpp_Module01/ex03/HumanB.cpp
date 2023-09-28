#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks their " << this->weapon.getType()
		<< std::endl;
}
