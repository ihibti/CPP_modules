#include"easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return it;
    }
    throw std::out_of_range("value not found");
}