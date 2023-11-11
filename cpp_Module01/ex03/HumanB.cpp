#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (!weapon)
		std::cout << "NO WEAPON" << std::endl;
	else
		std::cout << this->name << " attacks their " << this->weapon->getType() << std::endl;
}
