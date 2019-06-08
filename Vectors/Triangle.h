#pragma once
#include "Point.h"
#include "Vector.h"
#include <iostream>


class Triangle
{
	Point a, b, c;
	bool isPointInTriangle(Point p);
	double getLenghtOfSide(Point a, Point b);

public:
	Triangle();
	Triangle(const Point & a, const Point & b, const Point & c);
	std::string type();
	Point medicentre();
	double perimeter();
	double area();
	bool operator>(const Point & rhs);
	bool operator<(const Point & rhs);
	bool operator==(const Point & rhs);
	~Triangle();

};


