#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType(void)
{
	std::string& a = this->type;
	return (a);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

Weapon::~Weapon()
{
}
