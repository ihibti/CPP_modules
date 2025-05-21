#ifndef ITER_HPP
#define ITER_HPP
#include <stdio.h>
#include<iostream>
#include<string>

template <typename T, typename Func>
void iter(T* array, int length, Func func) {
    for (int i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}




#endif
