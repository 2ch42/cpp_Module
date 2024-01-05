#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int key)
{
    typename T::iterator it = std::find(container.begin(), container.end(), key);
    if (it == container.end())
        throw (std::runtime_error("Given key doesn't exist!"));
    std::cout << "KEY FOUND! : " << *it << std::endl;
    return (it);
}

#endif