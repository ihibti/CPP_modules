#include "array.hpp"

template <typename T>
Array<T>::Array()
{
    _size = 0;
    _array= 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    _size = n;
    if (n == 0)
        _array = 0;
    else
        _array = new T[n];
}


template<typename T>
Array<T>::Array(const Array<T> &other)
{
    _size = other._size;

    if (_size == 0)
    {
        _array = 0;
        return;
    }

    _array = new T[_size];
    for (unsigned int i = 0; i < _size; ++i)
        _array[i] = other._array[i]; 
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other)
        return(*this);
    delete[] _array;
    if (other._size == 0)
    {
        _array = 0;
        _size = 0;
        return(*this);
    }
    _size = other._size;
    _array = new T[other._size];
    for(unsigned int i = 0; i < other._size;i++)
        _array[i] = other._array[i];
    return *this;
}

template <typename T>
Array<T>::~Array<T>()
{
    delete[] _array;
}


template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return(_array[index]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return(_array[index]);
}

template<typename T>
unsigned int Array<T>::size() const
{
    return(_size);
}
