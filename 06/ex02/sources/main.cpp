#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base*	p = generate();
	Base&	r = *p;

	identify(p);
	identify(r);

	delete (p);
}
