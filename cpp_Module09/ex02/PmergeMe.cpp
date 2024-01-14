#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>

PmergeMe::PmergeMe() : _type(0) {}

PmergeMe::PmergeMe(const PmergeMe& pmm) : _type(pmm._type)
{
    this->_lst = pmm._lst;
    this->_vec = pmm._vec;
}

PmergeMe&   PmergeMe::operator=(const PmergeMe& pmm)
{
    if (this != &pmm)
    {
        this->_lst = pmm._lst;
        this->_vec = pmm._vec;
        this->_type = pmm._type;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::set_type(int type)
{
    this->_type = type;
}

const int   PmergeMe::get_type(const int& type) const
{
    return (this->_type);
}

void    PmergeMe::oper_list(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);
        int n;
        std::stringstream ss;
        ss.str(s);
        ss >> n;
        if (!ss.eof() || ss.fail())
            throw(std::runtime_error("Error"));
        this->_lst.push_back(n);
    }
    //[...]
}

void    PmergeMe::oper_vector(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);
        int n;
        std::stringstream ss;
        ss.str(s);
        ss >> n;
        if (!ss.eof() || ss.fail())
            throw(std::runtime_error("Error"));
        this->_vec.push_back(n);
    }
    // [...]
}

void    PmergeMe::print_list()
{
    std::cout << "After:   ";
    for(std::list<int>::iterator itr = this->_lst.begin(); itr != _lst.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::print_vector()
{
    std::cout << "After:   ";
    for(std::vector<int>::iterator itr = this->_vec.begin(); itr != _vec.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}