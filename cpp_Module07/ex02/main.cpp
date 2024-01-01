#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

/*
int main()
{
    try
    {
        Array<int> _int_zero;
        std::cout << "-----zero size int array created-----" << std::endl;
        std::cout << "Accessing Idx 0 : " << _int_zero[0] << std::endl;
        std::cout << "Accessing Idx 1 : " << _int_zero[1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Array<int> _int_ten(10);
        std::cout << "-----ten size int array created-----" << std::endl;
        std::cout << "Accessing Idx 0 : " << _int_ten[0] << std::endl;
        std::cout << "Accessing Idx 1 : " << _int_ten[1] << std::endl;
        std::cout << "Accessing Idx 10 : " << _int_ten[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Array<char> _char_ten(10);
        std::cout << "-----ten size char array created-----" << std::endl;
        std::cout << "Accessing Idx 0 : " << _char_ten[0] << std::endl;
        std::cout << "Accessing Idx 1 : " << _char_ten[1] << std::endl;
        std::cout << "Accessing Idx 10: " << _char_ten[10] << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}
*/