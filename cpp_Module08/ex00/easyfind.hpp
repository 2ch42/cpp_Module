#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int key)
{
    for(typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        if (*it == key)
        {
            std::cout << "KEY FOUND : " << *it << std::endl;
            return (it);
        }
    }
    throw (std::runtime_error("Given key doesn't exist!"));
}

#endif