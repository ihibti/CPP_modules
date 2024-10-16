#include "Serializer.hpp"

// Serialize: Converts a pointer to an integer
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Deserialize: Converts an integer back to a pointer
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

// Private constructor to prevent instantiation
Serializer::Serializer()
{
}
Serializer::Serializer(const Serializer &other)
{
    (void)other;
}
Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
	return (*this);
}
