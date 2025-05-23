#include <iostream>   // pour std::cerr, std::endl
#include <fstream>    // pour std::ifstream
#include <string>
#include<sstream>
#include<map>

bool isValidDate(const std::string &date)
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

    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

std::map<std::string, float> parseDatabase(std::ifstream &file)
{
    std::map<std::string, float> db;

    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line))
    {
        size_t sep = line.find(',');
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad database entry => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string rateStr = line.substr(sep + 1);

        std::istringstream iss(rateStr);
        float rate;
        iss >> rate;

        if (iss.fail() || !iss.eof())
        {
            std::cerr << "Error: bad rate in database => " << rateStr << std::endl;
            continue;
        }

        db[date] = rate;
    }

    return db;
}

