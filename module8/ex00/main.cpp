#include"easyfind.hpp"
#include"easyfind.tpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(13);
    vec.push_back(19);
    // we created a vector and inserted 4 elements
    // now lets to test easyfind
    std::cout << *easyfind(vec,10) << " | we were looking for 10 and we got it !"
    << std::endl;
    // now we ll try to test our exception feature
    try
    {
        std::cout << "we re now looking for a non exiting value" << std::endl;
        std::cout << *easyfind(vec,99990) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "mistake caught !" << std::endl;
    }
    std::list<int> myList;
    myList.push_back(5);
    myList.push_back(10);
    myList.push_back(15);

    std::cout << "\n--- Testing easyfind with std::list<int> ---" << std::endl;

    try {
        std::list<int>::iterator it = easyfind(myList, 10);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Looking for missing value in list..." << std::endl;
        easyfind(myList, 99);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // 

}
