#include <iostream>
#include "iter.hpp"

int main()
{
    std::cout << "-----INT ARR-----" << std::endl;
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    iter(arr, 10, &call);
    std::cout << "--------------" << std::endl;
    iter(arr, 10, &practice);

    std::cout << "-----CHAR ARR-----" << std::endl;
    char *str = new char[11];
    for (int i = 0; i < 10; i++)
    {
        *(str + i) = i + 48;
    }
    *(str + 10) = '\0';

    iter(str, 10, &call);

    delete[] arr;
    delete[] str;

    return (0);
}
