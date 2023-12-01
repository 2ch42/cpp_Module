#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* m_list[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& materiasource);
        MateriaSource& operator=(const MateriaSource& materiasource);
        ~MateriaSource();
        void    learnMateria(AMateria* m);
        AMateria* createMateria(std::string const& type);
};

#endif