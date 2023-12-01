#include <iostream>
#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const& type)
{
    if (type != "ice")
    {
        std::cout << "Unexpected case!" << std::endl;
        std::exit(0);
    }
    this->type = "ice";
    std::cout << "Ice type given constructor called" << std::endl;
}

Ice::Ice(const Ice& ice)
{
    this->type = "ice";
    if (this->type != "ice" || ice.type != "ice")
    {
        std::cout << "Unexpected case!" << std::endl;
        exit(0);
    }
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& ice)
{
    if (this != &ice)
        this->type = "ice";
    if (this->type != "ice" || this->type != "ice")
    {
        std::cout << "Unexpected case!" << std::endl;
        exit(0);
    }
    std::cout << "Ice copy assignment operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    AMateria* ice = new Ice();
    return (ice);
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}