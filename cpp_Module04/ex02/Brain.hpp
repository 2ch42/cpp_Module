#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        std::string *ideas;
    public:
        Brain();
        Brain(const Brain& brain);
        Brain& operator=(const Brain& brain);
        ~Brain();
        void    setIdea(int idx, const std::string& idea);
        std::string    getIdea(int idx) const;
};

#endif