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

void    merge_deq(std::deque<int>& _big, std::deque<int>& _small, int left, int right)
{
    int i = left;
    int mid = (left + right) / 2;
    int j = mid + 1;
    int k = left;
    std::deque<int> temp1(_big.size());
    std::deque<int> temp2(_small.size());

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
    while (j <= right)
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

void    rec_sort_deq(std::deque<int>& _big, std::deque<int>& _small, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        rec_sort_deq(_big, _small, left, mid);
        rec_sort_deq(_big, _small, mid + 1, right);
        merge_deq(_big, _small, left, right);
    }
}

void    bin_insert_deq(std::deque<int>& _big, int target)
{
    int left = 0;
    int right = _big.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (_big.at(mid) == target)
        {
            _big.insert(_big.begin() + mid, target);
            return ;
        }
        else if (_big.at(mid) > target)
            right = mid - 1;
        else
            left = mid + 1; 
    }
    if (_big.at(mid) < target)
        _big.insert(_big.begin() + mid + 1, target);
    else
        _big.insert(_big.begin() + mid, target);
}

void    insert_deq(std::deque<int>& _big, std::deque<int>& _small)
{
    _big.insert(_big.begin(), _small.at(0));
    int j_num = 3;
    if (_small.size() == 1)
        return ;
    while ((Jacob(j_num) < static_cast<int>(_small.size())))
    {
        for (int i = Jacob(j_num) - 1; i > Jacob(j_num - 1) - 1; i--)
        {
            bin_insert_deq(_big, _small.at(i));
        }
        j_num++;
    }
    for (int i = Jacob(--j_num); i < static_cast<int>(_small.size()); i++)
    {
        bin_insert_deq(_big, _small.at(i));
    }
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
    std::deque<int> _big;
    std::deque<int> _small;

    for(unsigned int i = 0; i < this->_deq.size(); i++)
    {
        if ((i % 2 == 0) && ((i + 1) < this->_deq.size()))
            _big.push_back(this->_deq.at(i));
        else
            _small.push_back(this->_deq.at(i));
    }
    for(unsigned int i = 0; i < _big.size(); i++)
    {
        if (_big.at(i) < _small.at(i))
            std::swap(_big.at(i), _small.at(i));
    }
    rec_sort_deq(_big, _small, 0, _big.size() - 1);
    insert_deq(_big, _small);
    for (unsigned int i = 0; i < _big.size(); i++)
    {
        this->_deq.at(i) = _big.at(i);
    }
    this->deq_end = clock();
}

void    merge_vec(std::vector<int>& _big, std::vector<int>& _small, int left, int right)
{
    int i = left;
    int mid = (left + right) / 2;
    int j = mid + 1;
    int k = left;
    std::vector<int> temp1(_big.size());
    std::vector<int> temp2(_small.size());

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
    while (j <= right)
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
        merge_vec(_big, _small, left, right);
    }
}

void    bin_insert_vec(std::vector<int>& _big, int target)
{
    int left = 0;
    int right = _big.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (_big.at(mid) == target)
        {
            _big.insert(_big.begin() + mid, target);
            return ;
        }
        else if (_big.at(mid) > target)
            right = mid - 1;
        else
            left = mid + 1; 
    }
    if (_big.at(mid) < target)
        _big.insert(_big.begin() + mid + 1, target);
    else
        _big.insert(_big.begin() + mid, target);
}

void    insert_vec(std::vector<int>& _big, std::vector<int>& _small)
{
    _big.insert(_big.begin(), _small.at(0));
    int j_num = 3;
    if (_small.size() == 1)
        return ;
    while ((Jacob(j_num) < static_cast<int>(_small.size())))
    {
        for (int i = Jacob(j_num) - 1; i > Jacob(j_num - 1) - 1; i--)
        {
            bin_insert_vec(_big, _small.at(i));
        }
        j_num++;
    }
    for (int i = Jacob(--j_num); i < static_cast<int>(_small.size()); i++)
    {
        bin_insert_vec(_big, _small.at(i));
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

    for(unsigned int i = 0; i < this->_vec.size(); i++)
    {
        if ((i % 2 == 0) && ((i + 1) < this->_vec.size()))
            _big.push_back(this->_vec.at(i));
        else
            _small.push_back(this->_vec.at(i));
    }
    for(unsigned int i = 0; i < _big.size(); i++)
    {
        if (_big.at(i) < _small.at(i))
            std::swap(_big.at(i), _small.at(i));
    }
    rec_sort_vec(_big, _small, 0, _big.size() - 1);
    insert_vec(_big, _small);
    for (unsigned int i = 0; i < _big.size(); i++)
    {
        this->_vec.at(i) = _big.at(i);
    }
    this->vec_end = std::clock();
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