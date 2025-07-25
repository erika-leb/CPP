#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(int x, int y) : _x(x), _y(y)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	// *this = src;
}
Point::~Point()
{
}
Point &Point::operator=(const Point &rhs)
{
	(void)rhs;
	if (this != &rhs)
		std::cout << "Assignment operator called — but Point has const members, so nothing can be assigned." << std::endl;
	return (*this);
}

const Fixed &Point::getX(void) const
{
	return(_x);
}
const Fixed &Point::getY(void) const
{
	return (_y);
}
