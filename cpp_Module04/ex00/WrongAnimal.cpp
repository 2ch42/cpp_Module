#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganmal) : type(wronganmal.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganmal)
{
    if (this != &wronganmal)
        this->type = wronganmal.type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal's make sound called" << std::endl;
}

std::string    WrongAnimal::getType() const
{
    return (this->type);
}