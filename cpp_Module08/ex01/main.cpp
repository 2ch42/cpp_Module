#include "Span.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "----- Test 1 -----" << std::endl;
        Span span(1);
        span.addNumber(10);
        std::cout << "Shortest Span..." << span.shortestSpan() << std::endl; //
        std::cout << "Longest Span..." << span.longestSpan() <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "----- Test 2 -----" << std::endl;
        Span span(10);
        for(int i = 0; i < 11; i++)
        {
            std::cout << "Adding Number " << i << std::endl;
            span.addNumber(i); // throw at 10
        }
        std::cout << "Shortest Span... " << span.shortestSpan() << std::endl; //
        std::cout << "Longest Span... " << span.longestSpan() <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "----- Test 3 -----" << std::endl;
        Span span(10);
        span.addNumber(1);
        span.addNumber(9);
        span.addNumber(8);
        span.addNumber(3);
        span.addNumber(7);
        span.addNumber(5);
        span.addNumber(4);
        span.addNumber(6);
        span.addNumber(2);
        span.addNumber(0);
        std::cout << "Shortest Span... " << span.shortestSpan() << std::endl; //
        std::cout << "Longest Span... " << span.longestSpan() <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "----- Test 4 -----" << std::endl;
        Span span(10000);
        span.addManyNumber();
        std::cout << "Shortest Span... " << span.shortestSpan() << std::endl; //
        std::cout << "Longest Span... " << span.longestSpan() <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}