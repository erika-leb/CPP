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
		Fixed operator+(const Fixed &rhs);
		Fixed operator-(const Fixed &rhs);
		Fixed operator*(const Fixed &rhs);
		Fixed operator/(const Fixed &rhs);
		bool operator<(const Fixed &rhs)const;
		bool operator>(const Fixed &rhs)const;
		bool operator>=(const Fixed &rhs)const;
		bool operator<=(const Fixed &rhs)const;
		bool operator==(const Fixed &rhs)const;
		bool operator!=(const Fixed &rhs)const;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int	toInt(void) const;

		static Fixed &min(Fixed &n1, Fixed &n2);
		static Fixed const &min(Fixed const &n1, Fixed const &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
		static Fixed const &max(Fixed const &n1, Fixed const &n2);

	private:
		int					_n;
		static const int	_bit = 8;
} ;

std::ostream &operator<<(std::ostream &os, const Fixed &n);

#endif
