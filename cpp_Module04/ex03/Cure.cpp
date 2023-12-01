#include <iostream>
#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const& type)
{
    if (type != "cure")
    {
        std::cout << "Unexpected case!" << std::endl;
        std::exit(0);
    }
    this->type = "cure";
    std::cout << "Cure type given constructor called" << std::endl;
}

Cure::Cure(const Cure& cure)
{
    this->type = "cure";
    if (this->type != "cure" || cure.type != "cure")
    {
        std::cout << "Unexpected case!" << std::endl;
        exit(0);
    }
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& cure)
{
    if (this != &cure)
        this->type = "cure";
    if (this->type != "cure" || this->type != "cure")
    {
        std::cout << "Unexpected case!" << std::endl;
        exit(0);
    }
    std::cout << "Cure copy assignment operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    AMateria* cure = new Cure();
    return (cure);
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}