#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<string>
#include<iostream>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);

    Array& operator=(const Array& other);
    unsigned int size() const;

    ~Array();
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    

private:
    T* _array;
    unsigned int _size;
};

#endif