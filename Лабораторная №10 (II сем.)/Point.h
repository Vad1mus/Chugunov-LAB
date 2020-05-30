#pragma once
#include <iostream>

using std::ostream;

class Point
{
public:
	Point();
	Point(int a, int b);

	friend ostream& operator<< (ostream& os, const Point& obj);
	const bool operator< (const Point& obj) const;
	const bool operator> (const Point& obj) const;
	const bool operator== (const Point& obj) const;

private:
	int x;
	int y;
};

ostream& operator<< (ostream& os, const Point& obj);