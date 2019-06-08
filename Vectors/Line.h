#pragma once
#include "Vector.h"
#include <iostream>
class Line : public Vector
{
	Point p;
	Vector v;
public:
	Line(Vector v, Point p);
	Line(Point a, Point b);
	Line();
	double angle(Line l);
	Point getPoint();
	Vector getVector();
	Vector normalVector();
	Vector direction();
	bool operator+(Point);
	bool operator==(Line);
	bool operator||(Line);
	bool operator&&(Line);
	bool operator!=(Line);
	bool operator|(Line);
	~Line();
};

