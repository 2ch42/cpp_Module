#include <string>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : fail_bit(0) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& be)
: _original_m(be._original_m), _new_m(be._new_m), fail_bit(be.fail_bit) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& be)
{
    if (this != &be)
    {
        this->_original_m = be._original_m;
        this->_new_m = be._new_m;
        this->fail_bit = be.fail_bit;
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
        int idx = str.find(",");
        std::string pre_str = str.substr(0, idx);
        std::string post_str = str.substr(idx + 1);
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
        {
            std::string str2("Error: bad input => ");
            str2 += str;
            throw (std::runtime_error("str2"));
        }
        std::string pre_str = str.substr(0, idx - 1);
        std::string post_str = str.substr(idx + 1);
        std::stringstream ss;
        ss << post_str;
        int post_i;
        ss >> post_i;
        if (ss.fail())
        {
            this->fail_bit = 1;
            return ;
        }
        ss.clear();
        ss.str(str);
        float post_f;
        ss >> post_f;
        this->_new_m.insert(std::make_pair(pre_str, post_f));
    }
}

int date_checker(std::string date)
{
    int idx = date.find("-");
    if (idx != 4)
        return (1);
    idx = date.find("-", 5);
    if (idx != 7)
        return (1);
    std::string year = date.substr(0, 4);
    std::stringstream   ss;
    ss << year;
    int _year;
    ss >> _year;
    if (!ss.eof())
        return (1);
    std::string month = date.substr(5, 2);
    ss.clear();
    ss.str(month);
    int _month;
    ss >> _month;
    if (!ss.eof())
        return (1);
    std::string day = date.substr(8, 2);
    ss.clear();
    ss.str(day);
    int _day;
    ss >> _day;
    if (!ss.eof())
        return (1);
    if (!(_month >= 1 && _month <= 12))
        return (1);
    if (_day > 31)
        return (1);
    if (_day == 31)
    {
        if (_month == 2 || _month == 4 || _month == 6 || _month == 9 || _month == 11)
            return (1);
    }
    if (_day == 29 && _month == 2 && _year % 4 != 0)
        return (1);
    return (0);
}

int BitcoinExchange::error_checker(std::string date, float price)
{
    if (date_checker(date))
    {
        std::cerr << "Error: bad date => " << date << std::endl;
        return (1);
    }
    if (this->fail_bit)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (1);
    }
    if (price < 0)
    {
        std::cerr << "Error: not a pisitive number." << std::endl;
        return (1);
    }
    if (price > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (1);
    }
    return (0);
}

void    BitcoinExchange::print_result()
{
    for(std::map<std::string, float>::iterator itr = this->_new_m.begin();
    itr != this->_new_m.end(); itr++)
    {
        if (!error_checker(itr->first, itr->second))
        {
            std::map<std::string, float>::iterator ite = this->_original_m.upper_bound(itr->first);
            std::cout << itr->first << " => " << itr->second << " = " << itr->second * (--ite)->second << std::endl;
        }
    }
}