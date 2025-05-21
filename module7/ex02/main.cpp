#include "array.hpp"
#include"array.tpp"

int main()
{
    Array<int> def_int;
    Array<char> def_char;
    if (def_int.size() == 0 && def_char.size() == 0)
        std::cout << "the default constructor works as intended!" << std::endl;
    Array<int> sized(10);
    for (unsigned int i= 0;i < sized.size();i++)
    {
        sized[i] = i+ 10;
    }
    std::cout << "size should be 10 :"<< sized.size() << std::endl;
    for (unsigned int i= 0;i < sized.size();i++)
    {
        std:: cout << sized[i] << " ";
    }
    std:: cout << std::endl;
    std:: cout << " so the [] works and the size constructor works also" << std::endl;

    Array<int> copy(sized);
    sized[0] = 99;
    for (unsigned int i= 0;i < sized.size();i++)
    {
        std:: cout << sized[i] << " : " << copy[i] <<  std::endl;
    }
    std::cout << "copy constructor worked ! and .size() works and first iteration shows deep copy"
     << std::endl;

    Array<int> equaled = copy;
    for (unsigned int i= 0;i < copy.size();i++)
    {
        std:: cout << equaled[i] << " : " << copy[i] <<  std::endl;
    }
    std::cout << "assignment operator  worked !" << std::endl;
    try{
        std::cout << copy[90];
    }
    catch(std::exception &e)
    {
        // (void)e;
        std::cerr << "WOOPS but proved the exceptions worked well !";
    }
    

}