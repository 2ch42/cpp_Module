#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "Default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
   std::cout << "Default scavtrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "Name passed scavtrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
    this->name = scavtrap.name;
    this->hit_points = scavtrap.hit_points;
    this->energy_points = scavtrap.energy_points;
    this->attack_damage = scavtrap.attack_damage;
    std::cout << "Copy scavtrap constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
    if (this != &scavtrap)
    {
        this->name = scavtrap.name;
        this->hit_points = scavtrap.hit_points;
        this->energy_points = scavtrap.energy_points;
        this->attack_damage = scavtrap.attack_damage;
    }
    std::cout << "Copy scavtrap assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap destructor Called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (!(this->hit_points) || !(this->energy_points))
    {
        std::cout << "ScavTrap " << this->name << " cannot do anything!" << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << "ScavTrap " << this->name << " attacks " << target;
    std::cout << " causing " << this->attack_damage << " points of damage!" << std::endl; 
}

void    ScavTrap::guardGate()
{
    std::cout << "Scavtrap name " << this->name << " is now in gate keeper mode!" << std::endl;
}
