#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

	public:
		Point(void);
		Point(int x, int y);
		Point(Point const &src);
		Point &operator=(Point const &src);
		~Point(void);

	private:
		Fixed _x;
		Fixed _y;
};

#endif
