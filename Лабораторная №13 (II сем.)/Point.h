#pragma once
#include <iostream>

using std::ostream;
using std::istream;

class Point
{
public:
	Point();
	Point(int a, int b);

	friend ostream& operator<< (ostream& os, const Point& obj);
	friend istream & operator>>(istream &is, Point &obj);
	const bool operator< (const Point& obj) const;
	const bool operator> (const Point& obj) const;
	const bool operator== (const Point& obj) const;

private:
	int x;
	int y;
};

ostream& operator<< (ostream& os, const Point& obj);
istream & operator>>(istream &is, Point &obj);