#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <fstream>
# include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _original_m; // original db
        std::map<std::string, float> _new_m; // new db
        int fail_bit;
    public:
        BitcoinExchange(); // OCF
        BitcoinExchange(const BitcoinExchange& be); // OCF
        BitcoinExchange& operator=(const BitcoinExchange& be); // OCF
        ~BitcoinExchange(); // OCF
        void    fill_original(std::ifstream& file);
        void    fill_new(std::ifstream& file);
        int    error_checker(std::string date, float price);
        void    print_result();
};

#endif