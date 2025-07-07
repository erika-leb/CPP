# include "Point.hpp"

Point::Point(void) : _y(0), _x(0)
{
	return ;
}
Point::Point(int x, int y) : _y(y), _x(x)
{
	return ;
}
Point::Point(Point const &src) : _x(src._x), _y(src._y)
{
	return ;
}
Point &Point::operator=(Point const &src)
{
	if (this != &src)
	{
		this->_x = src._x;
		this->_y = src._y;
	}
	return (*this);
}

Point::~Point(void)
{
	return ;
}
