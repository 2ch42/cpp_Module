#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->name = "Default";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "Default fragtrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ScavTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "Name passed fragtrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap)
{
    this->name = fragtrap.name;
    this->hit_points = fragtrap.hit_points;
    this->energy_points = fragtrap.energy_points;
    this->attack_damage = fragtrap.attack_damage;
    std::cout << "Copy fragtrap constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
    if (this != &fragtrap)
    {
        this->name = fragtrap.name;
        this->hit_points = fragtrap.hit_points;
        this->energy_points = fragtrap.energy_points;
        this->attack_damage = fragtrap.attack_damage;
    }
    std::cout << "Copy fragtrap assignment operator called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Fragtrap destructor Called" << std::endl;
}

void    FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap name " << this->name << " says high fives guys!" << std::endl;
}
