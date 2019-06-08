#pragma once
#include <iostream>
#include "Element.h"
class Point : public Element
{
	double x;
	double y;
	double z;

public:
	Point();
	Point(double x1, double y1, double z1);
	Point(const Point & P);
	double getX()const;
	double getY()const;
	double getZ()const;
	void setX(double x);
	void setY(double y);
	void setZ(double z);

	Point & operator=(const Point &);
	bool operator==(const Point &) const;
	



	~Point();
	friend std::ostream& operator<<(std::ostream&, Point&);
	friend std::istream& operator>>(std::istream&, Point&);


};

