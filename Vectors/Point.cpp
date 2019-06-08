#include "Point.h"
#include <iostream>


Point::Point()
{
}

Point::Point(double x, double y, double z) : x(x),y(y),z(z)
{
}

Point::Point(const Point & p)
{
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

Point & Point::operator=(const Point & p)
{
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
	return *this;
}

bool Point::operator==(const Point & p) const
{
	if (this->x == p.x && this->y == p.y && this->z == p.z) {
		return true;
	}
	return false;
}

double Point::getX()const
{
	return x;
}

double Point::getY()const
{
	return y;
}

double Point::getZ()const
{
	return z;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

void Point::setZ(double z)
{
	this->z = z;
}


Point::~Point()
{
}

std::ostream & operator<<(std::ostream & os, Point & p)
{
	os << "x: " << p.x << " y: " << p.y << " z: " << p.z << std::endl;
	return os;

}

std::istream & operator>>(std::istream & i, Point & p)
{
	i >> p.x >> p.y >> p.z;
	return i;
}
