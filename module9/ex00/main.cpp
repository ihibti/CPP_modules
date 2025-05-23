#include <iostream>   // pour std::cerr, std::endl
#include <fstream>    // pour std::ifstream
#include <string>
#include<sstream>
#include<map>

int main(int ac ,char **av)
{
    if (ac != 2)
    {
        std::cerr << "usage : " << av[0] << " filename" << std::endl;
        return (1);
    }
    std::ifstream data("resources/data.csv");
    if (data.fail())
    {
        std::cerr << "error trying to open the data.csv " << std::endl;
        return(1);
    }
    std::ifstream inputfile(av[1]);
    if (inputfile.fail())
    {
        std::cerr << "error trying to open the file: " << av[1] << std::endl;
        return(1);
    }
    std::string line;
    std::getline(inputfile, line);
    while(std::getline(inputfile, line))
    {
        size_t sep = line.find("|");
        if (sep == std::string::npos)
        {
            std::cerr<< "Error: bad input =>" << line << std::endl ;
            continue;
        }
        std::string date = line.substr(0,sep);
        std::string valueStr = line .substr(sep + 2);
        std::istringstream iss(valueStr);
        if (iss.fail() || !iss.eof())
        {
            std::cerr << "Error: bad value => " << valueStr << std::endl;
            continue;
        }
        float value;
        iss >> value;
        if (value < 0)
        {
            std::cerr << "Error: negative number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large number." << std::endl;
            continue;
        }

    }

    
}