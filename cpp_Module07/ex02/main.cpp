#include "Array.hpp"
#include <iostream>

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