#pragma once
#include <iostream>

using std::ostream;
using std::istream;

class PointOfPlane
{
public:
	PointOfPlane();
	PointOfPlane(int a, int b);
	explicit PointOfPlane(const PointOfPlane& obj);

protected:
	int x;
	int y;

private:
	friend ostream& operator<< (ostream& os, const PointOfPlane& obj);
	friend istream& operator>> (istream &is, PointOfPlane &obj);
	const bool operator< (const PointOfPlane& obj) const;
	const bool operator> (const PointOfPlane& obj) const;
	const bool operator== (const PointOfPlane& obj) const;
};

ostream& operator<< (ostream& os, const PointOfPlane& obj);
istream& operator>> (istream &is, PointOfPlane &obj);

class PointOfSpace : public PointOfPlane
{
public:
	PointOfSpace();
	PointOfSpace(int a, int b, int c);

private:
	int z;

	friend ostream& operator<< (ostream& os, const PointOfSpace& obj);
	friend istream& operator>> (istream &is, PointOfSpace &obj);
	const bool operator< (const PointOfSpace& obj) const;
	const bool operator> (const PointOfSpace& obj) const;
	const bool operator== (const PointOfSpace& obj) const;
};

ostream& operator<< (ostream& os, const PointOfSpace& obj);
istream& operator>> (istream &is, PointOfSpace &obj);