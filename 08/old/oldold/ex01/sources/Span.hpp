#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>
#include <limits>

class Span {

	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &rhs);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

	private:
		unsigned int _n;
		std::vector<int> _v;

		Span();

} ;

#endif
