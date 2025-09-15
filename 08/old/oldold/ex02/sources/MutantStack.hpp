#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack():std::stack<T>() {}
		MutantStack(const MutantStack &src) : std::stack<T>(src){}
		~MutantStack(){}
		MutantStack &operator=(const MutantStack &rhs)
		{
			if (this != &rhs)
			{
				this->c = rhs.c;
			}
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		typename std::stack<T>::container_type::iterator begin()
		{
			return (this->c.begin());
		}

		typename std::stack<T>::container_type::iterator end() {return (this->c.end());}
} ;

#endif
