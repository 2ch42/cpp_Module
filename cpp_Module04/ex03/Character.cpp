#include <iostream>
#include "Character.hpp"

Character::Character() : name("Default")
{
    for(int i = 0; i < 4; i++)
    {
        this->slots[i] = NULL;
    }
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string name) : name(name)
{
    for(int i = 0; i < 4; i++)
    {
        this->slots[i] = NULL;
    }
    std::cout << "Character name given constructor called" << std::endl;
}

Character::Character(const Character& character) : name(character.getName())
{
    for(int i = 0; i < 4; i++)
    {
        if (character.slots[i])
            this->slots[i] = character.slots[i]->clone();
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& character)
{
    if (this != &character)
    {
        this->name = character.getName();
    }
    for(int i = 0; i < 4; i++)
    {
        if (this->slots[i])
            delete (this->slots[i]);
        if (character.slots[i])
            this->slots[i] = character.slots[i]->clone();
    }
    return (*this);
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        if (this->slots[i])
            delete (this->slots[i]);
    }
    if (this->trash)
        delete (this->trash);
    std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName() const
{
    return (this->name);
}

void    Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Wrong Access" << std::endl;
        return ;
    }
    if (m->getType() != "ice" && m->getType() != "cure")
    {
        std::cout << "Wrong AMateria type given" << std::endl;
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        if (this->slots[i] == NULL)
        {
            this->slots[i] = m;
            return ;
        }
    }
    std::cout << "No empty space left in AMateria list" << std::endl;
}

void    Character::unequip(int idx)
{
    if (!(idx < 4 && idx >= 0))
    {
        std::cout << "Wrong idx given" << std::endl;
        return ;
    }
    if (this->slots[idx] == NULL)
    {
        std::cout << "No AMateria found in idx " << idx << std::endl;
        return ;
    }
    this->trash = slots[idx];
    slots[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target)
{
    if (!(idx < 4 && idx >= 0))
    {
        std::cout << "Wrong idx given" << std::endl;
        return ;
    }
    if (this->slots[idx] == NULL)
    {
        std::cout << "Wrong Access" << std::endl;
        return ;
    }
    if (this->slots[idx]->getType() != "ice" && this->slots[idx]->getType() != "cure")
    {
        std::cout << "Character Material type not ice nor cure" << std::endl;
        return ;
    }
    this->slots[idx]->use(target);
}