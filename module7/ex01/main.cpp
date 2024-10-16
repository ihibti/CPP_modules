#include "iter.hpp"
#include <iostream>

// Function to be applied to each element of the array
void printInt(int x) {
    std::cout << x << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

// Generic function template for testing
template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main() {
    // Test with int array
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(intArray, 5, printInt);  // Using the specific print function
    std::cout << std::endl;

    // Test with string array
    std::string strArray[] = {"hello", "world", "C++", "templates"};
    std::cout << "String array: ";
    iter(strArray, 4, printString);  // Using the specific print function
    std::cout << std::endl;

    // Test with a generic function template
    std::cout << "Int array (generic function): ";
    iter(intArray, 5, printElement<int>);  // Using the generic print template
    std::cout << std::endl;

    std::cout << "String array (generic function): ";
    iter(strArray, 4, printElement<std::string>);  // Using the generic print template
    std::cout << std::endl;

    return 0;
}
