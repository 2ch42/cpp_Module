#include <string>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& be)
: _original_m(be._original_m), _new_m(be._new_m) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& be)
{
    if (this != &be)
    {
        this->_original_m = be._original_m;
        this->_new_m = be._new_m;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void    BitcoinExchange::fill_original(std::ifstream& file)
{
    if (!(file.is_open()))    
        throw (std::runtime_error("Error: could not open file."));
    std::string str;
    while (1)
    {
        std::getline(file, str, '\n');
        if (str == "")
            break;
        std::string pre_str = str.substr(0, 10);
        std::string post_str = str.substr(11);
        std::stringstream ss;
        ss << post_str;
        float post_f;
        ss >> post_f;
        this->_original_m.insert(std::make_pair(pre_str, post_f));
    }
}

void    BitcoinExchange::fill_new(std::ifstream& file)
{
    if (!(file.is_open()))
        throw (std::runtime_error("Error: could not open file."));
    std::string str;
    while (1)
    {
        std::getline(file, str, '\n');
        if (str == "")
            break;
        int idx = str.find("|");
        if (idx < 0)
            throw (std::runtime_error("Error: contains wrong format."));
        std::string pre_str = str.substr(0, idx);
        std::string post_str = str.substr(idx + 1);
        std::stringstream ss;
        ss << post_str;
        float post_f;
        ss >> post_f;
        this->_new_m.insert(std::make_pair(pre_str, post_f));
    }
}

void    BitcoinExchange::print_result()
{
    for(std::map<std::string, float>::iterator itr = this->_new_m.begin();
    itr != this->_new_m.end(); itr++)
    {
        if (!error_checker(itr->first, itr->second))
            //cout
    }
}