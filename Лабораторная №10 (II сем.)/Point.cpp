#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

const bool Point::operator<(const Point & obj) const
{
	return (this->x + this->y) < (obj.x + obj.y);
}

const bool Point::operator==(const Point & obj) const
{
	return (this->x + this->y) == (obj.x + obj.y);
}

const bool Point::operator>(const Point & obj) const
{
	return (this->x + this->y) > (obj.x + obj.y);
}

ostream & operator<<(ostream & os, const Point & obj)
{
	os << '(' << obj.x << " ; " << obj.y << ')';
	return os;
}
