#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void    call(T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void    iter(T *arr, int length, void (*func)(T& ))
{
    for(int i = 0; i < length; i++)
    {
        func(*(arr + i));
    }
}

#endif