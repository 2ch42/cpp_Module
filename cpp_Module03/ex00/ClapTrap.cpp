#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Name passed constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
    this->name = new std::string(claptrap.get_name());//
    this->hit_points = claptrap.get_hp();
    this->energy_points = claptrap.get_ep();
    this->attack_damage = claptrap.get_ad();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
    if (this != &claptrap)
    {
        this->name = claptrap.name;
    }
}

std::string ClapTrap::get_name(void) const
{
    return (this->name);
}

void    ClapTrap::set_name(std::string name)
{
    this->name = name;
}

int ClapTrap::get_hp(void) const
{
    return (this->hit_points);
}

void    ClapTrap::set_hp(int hit_points)
{
    this->hit_points = hit_points;
}

int ClapTrap::get_ep(void) const
{
    return (this->energy_points);
}

void    ClapTrap::set_ep(int energy_points)
{
    this->energy_points = energy_points;
}

int ClapTrap::get_ad(void) const
{
    return (this->attack_damage);
}

void    ClapTrap::set_ad(int attack_damage)
{
    this->attack_damage = attack_damage;
}