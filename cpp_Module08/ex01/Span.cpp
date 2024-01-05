#include <stdexcept>
#include <vector> 
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

Span::Span() : idx(0), size(0) {}

Span::Span(const Span& span) : idx(span.idx), size(span.size) {}

Span& Span::operator=(const Span& span)
{
    if (this != &span)
    {
        this->dq = span.dq;
        this->idx = span.idx;
        this->size = span.size;
    }
    return (*this);
}

Span::Span(unsigned int N) : idx(0), size(N) {}

Span::~Span() {}

void    Span::addNumber(int new_val)
{
    if (idx >= size)
        throw(std::runtime_error("Out Of Bounds!"));
    this->dq.push_back(new_val);
    this->idx++;
}

void    Span::addManyNumber()
{
    srand(time(NULL));
    for(unsigned int i = idx; i < 10000; i++)
    {
        if (i >= this->size)
            throw(std::runtime_error("Out Of Bounds!"));
        this->dq.push_back(rand() % 10000);
    }
}

unsigned int    Span::shortestSpan()
{
    if (size < 2)
        throw(std::runtime_error("Require Minimum Size Of Container!"));
    int shortest = std::abs(*(dq.begin() + 1) - *(dq.begin()));
    for (std::deque<int>::iterator it = this->dq.begin(); it != (dq.end() - 1); it++)
    {
        if (std::abs(*(it + 1) - *it) < shortest)
            shortest = std::abs(*(it + 1) - *it);
    }
    return (static_cast<unsigned int>(shortest));
}

unsigned int    Span::longestSpan()
{
    if (size < 2)
        throw(std::runtime_error("Require Minimum Size Of Container!"));
    int longest = std::abs(*(dq.begin() + 1) - *(dq.begin()));
    for (std::deque<int>::iterator it = this->dq.begin(); it != (dq.end() - 1); it++)
    {
        if (std::abs(*(it + 1) - *it) > longest)
            longest = std::abs(*(it + 1) - *it);
    }
    return (static_cast<unsigned int>(longest));
}