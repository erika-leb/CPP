#ifndef FIXED_HPP
# define FIXED_HPP

# include "iostream"

class Fixed {

	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rhs);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					_n;
		static const int	_bit = 8;
} ;

#endif
