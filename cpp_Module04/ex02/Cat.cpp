#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& cat)
{
    this->type = cat.type;
    this->brain = new Brain;
    for(int i = 0; i < 100; i++)
    {
        this->brain->setIdea(i, cat.brain->getIdea(i));
    }
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        this->type = cat.type;
        this->brain = new Brain;
        for(int i = 0; i < 100; i++)
        {   
            this->brain->setIdea(i, cat.brain->getIdea(i));
        }
    }
    return (*this);
}

Cat::~Cat()
{
    if (this->brain)
        delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "MEOW!" << std::endl;
}