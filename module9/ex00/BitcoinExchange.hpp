#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;

public:
    BitcoinExchange(std::ifstream &dataFile);
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);
    float computeRate(const std::string &date, float value) const;
    static bool isValidDate(const std::string &date);
};

#endif
