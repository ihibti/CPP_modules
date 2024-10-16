#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>
class Serializer
{
  public:
	// Static methods for serialization and deserialization
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

  private:
	// Private constructor to prevent instantiation
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
};

#endif
