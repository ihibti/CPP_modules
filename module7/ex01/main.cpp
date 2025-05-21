#include "iter.hpp"



// fonctions pour comparer le template
// avec une "fonction normale"
void printInt(int x) {
    std::cout << x << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}


int main() {
    int intArray[] = {1, 2, 3, 4, 5};

    
    std::cout << "Int array: ";
    iter(intArray, 5, printInt);  // fonction normale
    std::cout << std::endl;

    // Test with string array
    std::string strArray[] = {"hello", "world", "C++", "templates"};
    std::cout << "String array: ";
    iter(strArray, 4, printString);  // fonction normale
    std::cout << std::endl;

    // Test with a generic function template
    std::cout << "Int array (generic function): ";
    iter(intArray, 5, printElement<int>);  // template
    std::cout << std::endl;

    std::cout << "String array (generic function): ";
    iter(strArray, 4, printElement<std::string>);  //template
    std::cout << std::endl;

    return 0;
}
