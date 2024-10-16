#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*deserializedData;

	data.id = 123;
	data.name = "Test Data";
	raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;
	deserializedData = Serializer::deserialize(raw);
	if (deserializedData == &data)
	{
		std::cout << "Deserialization successful!" << std::endl;
		std::cout << "Deserialized Data - ID: " << deserializedData->id;
		std::cout << ",Name: " << deserializedData->name << std::endl;
	}
	else
	{
		std::cerr << "Deserialization failed!" << std::endl;
	}
	return (0);
}
