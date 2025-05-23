#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream dataFile("resources/data.csv");
    if (!dataFile)
    {
        std::cerr << "Error: could not open data.csv" << std::endl;
        return 1;
    }

    
    std::ifstream inputFile(av[1]);
    if (!inputFile)
    {
        std::cerr << "Error: could not open file: " << av[1] << std::endl;
        return 1;
    }
    BitcoinExchange btc(dataFile);
    std::string line;
    std::getline(inputFile, line); // skip header

    while (std::getline(inputFile, line))
    {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);
        float value;
        std::istringstream iss(valueStr);
        iss >> value;

        if (!BitcoinExchange::isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (iss.fail() || !iss.eof())
        {
            std::cerr << "Error: bad value => " << valueStr << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try
        {
            float result = btc.computeRate(date, value);
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
