#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

/* OCF */

PmergeMe::PmergeMe() {} // OCF

PmergeMe::PmergeMe(const PmergeMe& pmm) // OCF
{
    this->_deq = pmm._deq;
    this->_deq = pmm._deq;
}

PmergeMe&   PmergeMe::operator=(const PmergeMe& pmm) // OCF
{
    if (this != &pmm)
    {
        this->_deq = pmm._deq;
        this->_deq = pmm._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {} //OCF

/*   sorting funcs    */

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
void    sort_vector()
{

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
    for(unsigned int i = 0; i < this->_vec.size(); i++)
    {
        if ((i % 2 == 0) && (i + 1 < this->_vec.size()))
        {
            if (this->_vec.at(i) < this->_vec.at(i + 1))
            {
                int temp = this->_vec.at(i);
                this->_vec.at(i) = this->_vec.at(i + 1);
                this->_vec.at(i + 1) = temp;
            }
        }
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