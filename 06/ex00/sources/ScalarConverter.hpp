#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits.h>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>
#include <climits>

class ScalarConverter {

	public:
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &rhs);

		static void convert(const std::string &str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
} ;

#endif
