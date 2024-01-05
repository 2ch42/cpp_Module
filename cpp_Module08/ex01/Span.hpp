#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int idx;
        unsigned int size;
    public:
        Span(); // OCF
        Span(const Span& span); // OCF
        Span& operator=(const Span& span); // OCF
        ~Span(); // OCF
        Span(unsigned int N);
        void    addNumber(int new_val); //throw when idx >= size
        void    addManyNumber(); // 10,000 numbers
        unsigned int    shortestSpan(); // throw when size < 2
        unsigned int    longestSpan(); // throw when size < 2
};

#endif