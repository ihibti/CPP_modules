#include "identify.hpp"
#include <iostream>

int main() {
    Base* basePtr = generate();
    D test;
    Base *d_ptr = &test;
    
    // can add another derived class to show 
    // the scenario where it s neither a b or c
    // for correction purposes i added a d class 
    //derived from Base
    std::cout << "Identify using pointer: ";
    identify(basePtr);
    std::cout << "Identify using reference: ";
    identify(*basePtr);
    std::cout << "Identify using pointer: ";
    identify(d_ptr);
    std::cout << "Identify using reference: ";
    identify(*d_ptr);
    delete basePtr;
    return 0;
}
