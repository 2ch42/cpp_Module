#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN& r);
        RPN& operator=(const RPN& r);
        ~RPN();
        void    calculate(char *str); // should except when stack size zero
        int get_result();
};

int is_oper(char c);

#endif