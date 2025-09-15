#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>

class Span {

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &rhs);

		void addNumber(int n);
		long shortestSpan();
		long longestSpan();
		void addRange(std::vector<int>::iterator a, std::vector<int>::iterator b);


	private:
		unsigned int _n;
		std::vector<int> _v;
} ;

#endif
