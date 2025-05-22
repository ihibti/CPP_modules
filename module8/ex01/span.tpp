#include "span.hpp"

template<typename It>
void Span::addNumber(It begin, It end)
{
    if (_storage.size() + std::distance(begin,end) > _maxSize)
        throw std::out_of_range("not ebough space in span");
    for (It current = begin;current != end;++current)
        addNumber(*current);
}