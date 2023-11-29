#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
    this->type = dog.type;
    this->brain = new Brain;
    for(int i = 0; i < 100; i++)
    {
        this->brain->setIdea(i, dog.brain->getIdea(i));
    }
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        this->type = dog.type;
        this->brain = new Brain;
        for(int i = 0; i < 100; i++)
        {
            this->brain->setIdea(i, dog.brain->getIdea(i));
        }
    }
    return (*this);
}

Dog::~Dog()
{
    if (this->brain)
        delete (this->brain);
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "BARK!" << std::endl;
}