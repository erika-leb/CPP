#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array &operator=(const Array &rhs);

		T &operator[](unsigned int n) const;
		unsigned int size() const;

	private:
		T * _arr;
		unsigned int _n;
} ;

#endif
