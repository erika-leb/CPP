#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &rhs);

		void addNumber(int nb);
		int shortestSpan();
		int longestSpan();
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
		unsigned int _n;
		std::vector<int> _v;
} ;

#endif
