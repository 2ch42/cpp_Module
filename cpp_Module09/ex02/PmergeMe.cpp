#include "PmergeMe.hpp"

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

const int   get_type(const int& type) const
{
    
}