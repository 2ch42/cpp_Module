#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string const& type);
        Ice(const Ice& ice);
        Ice& operator=(const Ice& ice);
        ~Ice();
        AMateria* clone() const;
        void    use(ICharacter& target);
};

#endif