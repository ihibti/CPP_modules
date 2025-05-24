#include"PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe test;
    try 
    {
    test.parseArguments(ac,av);
    test.printBefore();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}