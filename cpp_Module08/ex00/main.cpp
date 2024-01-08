#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    try
    {
        std::cout << "-----Testing vector..-----" << std::endl;
        std::vector<int> int_vec;
        int_vec.push_back(10);
        int_vec.push_back(20);
        int_vec.push_back(30);
        int_vec.push_back(40);
        int_vec.push_back(50);
        std::vector<int>::iterator it = easyfind(int_vec, 20);
        it = easyfind(int_vec, 70);
        it = easyfind(int_vec, 40);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "-----Testing list..-----" << std::endl;
        std::list<int> int_list;
        int_list.push_back(10);
        int_list.push_back(20);
        int_list.push_back(30);
        int_list.push_back(40);
        int_list.push_back(50);
        std::list<int>::iterator it = easyfind(int_list, 20);
        it = easyfind(int_list, 70);
        it = easyfind(int_list, 40);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "-----Testing deque..-----" << std::endl;
        std::deque<int> int_deque;
        int_deque.push_back(10);
        int_deque.push_back(20);
        int_deque.push_back(30);
        int_deque.push_back(40);
        int_deque.push_back(50);
        std::deque<int>::iterator it = easyfind(int_deque, 20);
        it = easyfind(int_deque, 70);
        it = easyfind(int_deque, 40);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}