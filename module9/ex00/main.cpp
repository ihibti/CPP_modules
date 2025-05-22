#include <iostream>   // pour std::cerr, std::endl
#include <fstream>    // pour std::ifstream


int main(int ac ,char **av)
{
    if (ac != 2)
    {
        std::cerr << "usage : " << av[0] << "filename" << std::endl;
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
    
}