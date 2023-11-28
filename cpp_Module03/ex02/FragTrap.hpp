#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& fragtrap);
        FragTrap& operator=(const FragTrap& fragtrap);
        ~FragTrap();
        void    highFiveGuys(void);
};

#endif