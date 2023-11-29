#include "Brain.hpp"

Brain::Brain()
{
    this->ideas = new std::string[100];
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = "Sample";
    }
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    this->ideas = new std::string[100];
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = brain.getIdea(i);
    }
}

Brain& Brain::operator=(const Brain& brain)
{
    if (this != &brain)
    {
        if (this->ideas)
            delete (this->ideas);
        this->ideas = new std::string[100];
        for(int i = 0; i < 100; i++)
        {
            this->ideas[i] = brain.getIdea(i);
        }
    }
    return (*this);
}

Brain::~Brain()
{
    if (ideas)
        delete[] ideas;
    std::cout <<"Brain destructor called" << std::endl;
}

void    Brain::setIdea(int idx, const std::string& idea)
{
    if (idx > 99 || idx < 0)
    {
        std::cout << "Given idx wrong" << std::endl;
        return ;
    }
    this->ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const
{
    if (idx > 99 || idx < 0)
    {
        std::cout << "Given idx wrong" << std::endl;
        return (NULL);
    }
    return (this->ideas[idx]);
}