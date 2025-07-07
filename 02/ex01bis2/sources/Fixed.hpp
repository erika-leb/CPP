#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const n);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int	toInt(void) const;

	private:
		int					_n;
		static const int	_bit = 8;
} ;

std::ostream &operator<<(std::ostream &os, const Fixed &n);

#endif
