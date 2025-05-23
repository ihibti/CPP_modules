#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        size_t sep = line.find(',');
        if (sep == std::string::npos)
            continue;

        std::string date = line.substr(0, sep);
        std::string rateStr = line.substr(sep + 1);

        std::istringstream iss(rateStr);
        float rate;
        iss >> rate;

        if (!iss.fail() && iss.eof())
            _database[date] = rate;
    }
}

float BitcoinExchange::computeRate(const std::string &date, float value) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    if (it == _database.begin() && it->first != date)
        throw std::runtime_error("Error: no earlier data available.");

    if (it == _database.end() || it->first != date)
        --it;

    return value * it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}


// tentative de resoudrre le probleme des jours avec un algo plus general mais 
// en haut c est plus simple
// s il y vait plus de moois dans l anne j aurias fait ca
// int monthtoday(int month, int year)
// {
//     if (month == 2)
//     {
//         if (year % 400 == 0)
//             return (29);
//         else if (year % 100)
//             return (28);
//         else if (year % 4 == 0)
//             return (29);
//         return (28);
//     }
//     else if ((month % 2 && month <= 7) || (month % 2 == 0 && month > 7))
//         return (31);
//     else
//         return (30);
// }

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other):_database(other._database){}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return *this;
    _database = other._database;
    return *this;

}
BitcoinExchange::~BitcoinExchange(){}



