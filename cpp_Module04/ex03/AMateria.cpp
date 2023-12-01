#include "AMateria.hpp"

AMateria::AMateria() : type("Default")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type)
{
    std::cout << "AMateria type given constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& amateria) : type(amateria.getType())
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& amateria)
{
    if (this != &amateria)
    {
        this->type = amateria.getType();
    }
    std::cout << "AMateria copy assignment operator called" << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called";
}

std::string const& AMateria::getType() const
{
    return (this->type);
}

void    AMateria::setType(const std::string& type)
{
    this->type = type;
}

/*
AMateria* AMateria::clone() const
{
}
*/

void    AMateria::use(ICharacter& target)
{
    std::cout << "* AMateria class itself name " << target.getName() << " is unexpected" << std::endl;
}