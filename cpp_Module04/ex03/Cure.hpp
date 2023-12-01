#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string const& type);
        Cure(const Cure& cure);
        Cure& operator=(const Cure& cure);
        ~Cure();
        AMateria* clone() const;
        void    use(ICharacter& target);
};

#endif