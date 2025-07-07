#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const  &src);
		Fixed &operator=(const Fixed &rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_n;
		static const int	_bit = 8;

} ;

#endif
