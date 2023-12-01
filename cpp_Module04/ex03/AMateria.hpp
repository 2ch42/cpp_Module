#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class   ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const& type);
        AMateria(const AMateria& amateria);
        AMateria& operator=(const AMateria& amateria);
        virtual ~AMateria();
        std::string const& getType() const;
        void    AMateria::setType(const std::string& type);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif