#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public :
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed &operator=(Fixed const &src);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
	private:
		int _n;
		static const int _bit = 8;
} ;

#endif
