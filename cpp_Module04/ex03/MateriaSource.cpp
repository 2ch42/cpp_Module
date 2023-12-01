#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        this->m_list[i] = NULL;
    }
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiasource)
{
    for(int i = 0; i < 4; i++)
    {
        if (materiasource.m_list[i])
            this->m_list[i] = materiasource.m_list[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiasource)
{
    if (this != &materiasource)
    {
        for(int i = 0; i < 4; i++)
        {
            if (this->m_list[i])
                delete (this->m_list[i]);
            if (materiasource.m_list[i])
                this->m_list[i] = materiasource.m_list[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    if (this->m_list)
        delete[] (this->m_list);
    std::cout << "MateriaSource destructor called" << std::endl;
}

void    MateriaSource::learnMateria(AMateria *m)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->m_list[i] == NULL)
        {
            this->m_list[i] = m;
            return ;
        }
    }
    std::cout << "No empty space left in materia list" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->m_list[i]->getType() == type)
            return (this->m_list[i]->clone());
    }
    std::cout << "Unknown Type Given" << std::endl;
    return (0);
}