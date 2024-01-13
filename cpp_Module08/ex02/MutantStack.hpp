#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{  
    public:
        MutantStack() {}
        MutantStack(const MutantStack& mutantstack)
        {
            *this = mutantstack;
        }
        MutantStack& operator=(const MutantStack& mutantstack)
        {
            if (this != &mutantstack)
                this->c = mutantstack.c;
            return (*this);
        }
        ~MutantStack() {}
        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator    begin() { return (this->c.begin()); }
        iterator    end() { return (this->c.end()); }
        iterator    rbegin() { return (this->c.rbegin()); }
        iterator    rend() { return (this->c.rend()); }
};

#endif