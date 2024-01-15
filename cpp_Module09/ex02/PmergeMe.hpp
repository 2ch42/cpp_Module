#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <ctime>

class PmergeMe
{
    private:
        std::deque<int> _deq;
        std::vector<int> _vec;
        clock_t deq_start;
        clock_t deq_end;
        clock_t vec_start;
        clock_t vec_end;
    public:
        PmergeMe(); // OCF
        PmergeMe(const PmergeMe& pmm); // OCF
        PmergeMe& operator=(const PmergeMe& me); // OCF
        ~PmergeMe(); // OCF
        void    oper_deq(int argc, char *argv[]);
        void    oper_vector(int argc, char *argv[]);
        void    print_deq();
        void    print_vector();
        void    print_time();
};

#endif