#include "Point.h"

PointOfPlane::PointOfPlane() : x(0), y(0)
{
}

PointOfPlane::PointOfPlane(int a, int b) : x(a), y(b)
{
}

PointOfPlane::PointOfPlane(const PointOfPlane & obj) : x(obj.x), y(obj.y)
{
}

const bool PointOfPlane::operator<(const PointOfPlane & obj) const
{
	return (this->x + this->y) < (obj.x + obj.y);
}

const bool PointOfPlane::operator==(const PointOfPlane & obj) const
{
	return (this->x + this->y) == (obj.x + obj.y);
}

const bool PointOfPlane::operator>(const PointOfPlane & obj) const
{
	return (this->x + this->y) > (obj.x + obj.y);
}

ostream & operator<<(ostream & os, const PointOfPlane & obj)
{
	os << '(' << obj.x << " ; " << obj.y << ')';
	return os;
}

istream & operator>>(istream &is, PointOfPlane &obj)
{
	std::cout << "\nВедите X: ";
	is >> obj.x;
	std::cout << "Введите Y: ";
	is >> obj.y;
	return is;
}

PointOfSpace::PointOfSpace() : PointOfPlane(), z(0)
{
}

PointOfSpace::PointOfSpace(int a, int b, int c) : PointOfPlane(a, b), z(c)
{
}

const bool PointOfSpace::operator<(const PointOfSpace & obj) const
{
	return (this->x + this->y + this->z) < (obj.x + obj.y + obj.z);
}

const bool PointOfSpace::operator>(const PointOfSpace & obj) const
{
	return (this->x + this->y + this->z) > (obj.x + obj.y + obj.z);
}

const bool PointOfSpace::operator==(const PointOfSpace & obj) const
{
	return (this->x + this->y + this->z) == (obj.x + obj.y + obj.z);
}

ostream & operator<<(ostream & os, const PointOfSpace & obj)
{
	os << '(' << obj.x << " ; " << obj.y << " ; " << obj.z << ')';
	return os;
}

istream & operator>>(istream & is, PointOfSpace & obj)
{
	std::cout << "\nВведите X: ";
	is >> obj.x;
	std::cout << "Введите Y: ";
	is >> obj.y;
	std::cout << "Введмте Z: ";
	is >> obj.z;
	return is;
}
