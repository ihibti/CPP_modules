#include"PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe test;
    try 
    {
        test.parseArguments(ac,av);
        test.printBefore();
        test.sortWithVector();
        test.sortWithDequeue();
        test.print_end();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}