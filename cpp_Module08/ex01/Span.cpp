#include <stdexcept>
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
        this->vec = span.vec;
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
    this->vec.push_back(new_val);
    this->idx++;
}

void    Span::addManyNumber()
{
    srand(time(NULL));
    for(unsigned int i = idx; i < 10000; i++)
    {
        if (i >= this->size)
            throw(std::runtime_error("Out Of Bounds!"));
        this->vec.push_back(rand() % 10000);
    }
}

unsigned int    Span::shortestSpan()
{
    if (size < 2)
        throw(std::runtime_error("Require Minimum Size Of Container!"));
    std::sort(vec.begin(), vec.end());
    int shortest = *(vec.begin() + 1) - *(vec.begin());
    for (std::vector<int>::iterator it = this->vec.begin(); it != (vec.end() - 1); it++)
    {
        if ((*(it + 1) - *it) < shortest)
            shortest = (*(it + 1) - *it);
    }
    return (static_cast<unsigned int>(shortest));
}

unsigned int    Span::longestSpan()
{
    if (size < 2)
        throw(std::runtime_error("Require Minimum Size Of Container!"));
    std::sort(vec.begin(), vec.end());
    return (*(vec.end() - 1) - *(vec.begin()));
}