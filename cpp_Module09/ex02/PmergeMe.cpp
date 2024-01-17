#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

/* OCF */

PmergeMe::PmergeMe() {} // OCF

PmergeMe::PmergeMe(const PmergeMe& pmm) // OCF
{
    this->_deq = pmm._deq;
    this->_vec = pmm._vec;
}

PmergeMe&   PmergeMe::operator=(const PmergeMe& pmm) // OCF
{
    if (this != &pmm)
    {
        this->_deq = pmm._deq;
        this->_vec = pmm._vec;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {} //OCF

/*   sorting funcs    */

int Jacob(int n)
{
    if (n < 0)
        throw(std::runtime_error("Error"));
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    else
        return (Jacob(n - 1) + 2 * Jacob(n - 2));
}

void    mergeInsert_deq()
{
    
}

void    PmergeMe::oper_deq(int argc, char *argv[])
{
    this->deq_start = std::clock();
    for(int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);
        int n;
        std::stringstream ss;
        ss.str(s);
        ss >> n;
        if (!ss.eof() || ss.fail())
            throw(std::runtime_error("Error"));
        this->_deq.push_back(n);
    }
    //[...]
    this->deq_end = std::clock();
}

void    merge(std::vector<int>& _big, std::vector<int>& _small, int left, int right)
{
    int i = left;
    int mid = (left + right) / 2;
    int j = mid + 1;
    int k = left;
    std::vector<int> temp1;
    std::vector<int> temp2;

    while (i <= mid && j <= right)
    {
        if (_big[i] <= _big[j])
        {
            temp1[k] = _big[i];
            temp2[k++] = _small[i++];
        }
        else
        {
            temp1[k] = _big[j];
            temp2[k++] = _small[j++];
        }
    }
    while (i <= mid)
    {
        temp1[k] = _big[i];
        temp2[k++] = _small[i++];
    }
    while (j <= mid)
    {
        temp1[k] = _big[j];
        temp2[k++] = _small[j++];
    }
    for(int idx = left; idx <= right; idx++)
    {
        _big[idx] = temp1[idx];
        _small[idx] = temp2[idx];
    }
}

void    rec_sort_vec(std::vector<int>& _big, std::vector<int>& _small, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        rec_sort_vec(_big, _small, left, mid);
        rec_sort_vec(_big, _small, mid + 1, right);
        merge(_big, _small, left, right);
    }
}

void    PmergeMe::oper_vector(int argc, char *argv[])
{
    this->vec_start = std::clock();
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
    std::vector<int> _big;
    std::vector<int> _small;

    for(int i = 0; i < this->_vec.size(); i++)
    {
        if ((i % 2 == 0) && ((i + 1) < this->_vec.size()))
            _big.push_back(this->_vec.at(i));
        else
            _small.push_back(this->_vec.at(i));
    }
    for(int i = 0; i < this->_vec.size(); i++)
    {
        if (_big.at(i) < _small.at(i))
            std::swap(_big.at(i), _small.at(i));
    }
    rec_sort_vec(_big, _small, 0, _big.size() - 1);
}

/*  print funcs  */

void    PmergeMe::print_deq()
{
    std::cout << "After:   ";
    for(std::deque<int>::iterator itr = this->_deq.begin(); itr != this->_deq.end(); itr++)
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

void    PmergeMe::print_time()
{
    std::cout << "Time to process a range of " << this->_deq.size()
        << " with std::deque : "
        << static_cast<double>(deq_end - deq_start) / CLOCKS_PER_SEC * 1000
        << " ms" << std::endl;
    std::cout << "Time to process a range of " << this->_vec.size()
        << " with std::vector : "
        << static_cast<double>(vec_end - vec_start) / CLOCKS_PER_SEC * 1000
        << " ms" << std::endl;
}