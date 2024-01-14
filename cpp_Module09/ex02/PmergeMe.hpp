#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>

class PmergeMe
{
    private:
        std::list<int> _lst;
        std::vector<int> _vec;
        int _type;
        //time spent by _lst;
        //timie spent by _vec;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& pmm);
        PmergeMe& operator=(const PmergeMe& me);
        ~PmergeMe();
        void    set_type(int _type);
        const int   get_type(const int& type) const;
        void    oper_list(int argc, char *argv[]);
        void    oper_vector(int argc, char *argv[]);
        void    print_list();
        void    print_vector();
        void    print_time();
};

#endif