#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &operator=(Fixed const &src);
		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs);
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);

		bool operator<(Fixed const &rhs) const;
		bool operator>(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed &min(Fixed &n1, Fixed &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
		static const Fixed &min(const Fixed &n1, const Fixed &n2);
		static const Fixed &max(const Fixed &n1, const Fixed &n2);

	private:
		int _n;
		static const int _bit = 8;
} ;

std::ostream &operator<<(std::ostream &os, const Fixed &n);

#endif
