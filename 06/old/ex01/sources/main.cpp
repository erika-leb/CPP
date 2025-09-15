#include "Serializer.hpp"

int main( void )
{
	Data data;
	data.value = 42;

	std::cout << "Original pointer: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized: " << raw << std::endl;

	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << deserialized << std::endl;

	std::cout << "Original value = " << data.value << std::endl;
	std::cout << "Deserialized value = " << deserialized->value << std::endl;

	return 0;
}
