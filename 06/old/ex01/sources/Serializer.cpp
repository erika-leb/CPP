# include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
	(void)src;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	(void) rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t r = reinterpret_cast<uintptr_t>(ptr);
	return (r);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *p = reinterpret_cast<Data*>(raw);
	return (p);
}
