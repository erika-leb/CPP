#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <stack>
# include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	public:
		MutantStack() : std::stack<T, Container>(){}
		MutantStack(const MutantStack &src) : std::stack<T, Container>(src){}
		~MutantStack() {}
		MutantStack &operator=(const MutantStack &rhs)
		{
			if (this != &rhs)
				this->c = rhs.c;
			return (*this);
		}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }
} ;

#endif
