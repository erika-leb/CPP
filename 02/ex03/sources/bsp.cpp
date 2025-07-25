#include "Point.hpp"

Fixed vectProd(Point p, Point a, Point b)
{
	Fixed res;
	res = (a.getX() - p.getX()) * (b.getY() - p.getY()) - (a.getY() - p.getY()) * (b.getX() - p.getX());
	return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed v1;
	Fixed v2;
	Fixed v3;

	v1 = vectProd(point, a, b);
	v2 = vectProd(point, b, c);
	v3 = vectProd(point, c, a);
	if ((v1 >= 0 && v2 >= 0 && v3 >= 0) || (v1 < 0 && v2 < 0 && v3 < 0))
		return (true);
	else
		return (false);
}
