#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <exception>
# include <cstdlib>  // pour rand()
# include <ctime>    // pour time()

class Base {

	public :
		virtual ~Base();

} ;

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
