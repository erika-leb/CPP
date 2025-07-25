#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

	public:
		Point();
		Point(int x, int y);
		Point(float x, float y);
		Point(const Point &src);
		~Point();
		Point &operator=(const Point &rhs);

		const Fixed &getX() const;
		const Fixed &getY()const;

	private:
		const Fixed _x;
		const Fixed _y;
} ;

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
