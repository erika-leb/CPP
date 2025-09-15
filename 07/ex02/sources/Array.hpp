#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array &operator=(const Array &rhs);

		unsigned int size() const;
		T &operator[](unsigned int n);
		const T &operator[](unsigned int n) const;

	private:
		unsigned int _n;
		T *_arr;
} ;

#endif
