#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Default claptrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Name passed claptrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
    this->name = claptrap.name;
    this->hit_points = claptrap.hit_points;
    this->energy_points = claptrap.energy_points;
    this->attack_damage = claptrap.attack_damage;
    std::cout << "Copy claptrap constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
    if (this != &claptrap)
    {
        this->name = claptrap.name;
        this->hit_points = claptrap.hit_points;
        this->energy_points = claptrap.energy_points;
        this->attack_damage = claptrap.attack_damage;
    }
    std::cout << "Copy claptrap assignment operator called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Claptrap destructor Called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (!(this->hit_points) || !(this->energy_points))
    {
        std::cout << "ClapTrap " << this->name << " cannot do anything!" << std::endl;
        return ;
    }
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " attacks " << target;
    std::cout << " causing " << this->attack_damage << " points of damage!" << std::endl; 
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
        return ;
    }
    if (this->hit_points < amount)
    {
        this->hit_points = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount;
        std::cout << " points of damage!" << std::endl;
        return ;
    }
    this->hit_points -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount;
    std::cout << " points of damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!(this->hit_points) || !(this->energy_points))
    {
        std::cout << "ClapTrap " << this->name << " cannot do anything!" << std::endl;
        return ;
    }
    this->energy_points--;
    this->hit_points += amount;
    std::cout << "ClapTrap " << this->name << " is repaired!(hit_points : + 10)" << std::endl;
}