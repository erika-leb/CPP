#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &operator=(Fixed const &src);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int					_n;
		static const int	_bit = 8;  //est-ce bien de faire ca ?

} ;

std::ostream& operator<<(std::ostream& os, const Fixed &copy);

#endif
