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
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& pmm);
        PmergeMe& operator=(const PmergeMe& me);
        ~PmergeMe();
        void    set_type(int _type);
        const int   get_type(const int& type) const;
        void    oper_list(char *str);
        void    oper_vector(char *str);
};

#endif