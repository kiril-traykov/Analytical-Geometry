#include "Triangle.h"
#include "Point.h"
#include "Vector.h"
#include <iostream>
#include "TriangleException.h"
#include <cMath>
#define PI 3.14

Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

Triangle::Triangle(const Point & a, const Point & b, const Point & c) : a(a),b(b),c(c) {
	
		if (a == b) throw  TriangleException();
		if (b == c) throw  TriangleException();
		if (c == a) throw  TriangleException();

	}
	


std::string Triangle::type()  {
	Vector ab(a, b);
	Vector ac(a, b);
	Vector bc(a, b);

	double a_angle = (ab * ac) / (ab.lenght() * ac.lenght());
	double b_angle = (ab * bc) / (ab.lenght() * bc.lenght());
	double c_angle = (bc * ac) / (bc.lenght() * ac.lenght());

	if (acos(a_angle) * 180 / PI == 90 || acos(b_angle) * 180 / PI == 90 || acos(c_angle) * 180 / PI == 90) return ("Right");

	else if (acos(a_angle) * 180 / PI > 90 || acos(b_angle) * 180 / PI > 90 || acos(c_angle) * 180 / PI > 90) return ("Acute");

    return ("Obtuse");

}

double Triangle::perimeter() {
	double per;
	per = getLenghtOfSide(a, b);
	per += getLenghtOfSide(a, c);
	per += getLenghtOfSide(b, c);

	return per;

}


double Triangle::area()  {
	double p = perimeter() / 2;
	return sqrt(p*(p - getLenghtOfSide(a,b))*(p - getLenghtOfSide(a,c))*(p - getLenghtOfSide(b,c)));
}

bool Triangle::isPointInTriangle(Point p)
{

	Vector ab(a, b);
	Vector ac(a, c);
	Vector bc(b, c);
	Vector pa(p, a);
	Vector pb(p, b);
	Vector pc(p, c);

	double area = (ab ^ ac).lenght() / 2;
	double aSide = (pb ^ pc).lenght() / (2 * area);
	double bSide = (pc ^ pa).lenght() / (2 * area);
	double cSide = 1 - aSide - bSide;

	if (aSide >= 0 && aSide <= 1 && bSide >= 0 && bSide <= 1 && cSide >= 0 && cSide <= 1)
	{
		return true;
	}
	return false;
}



Point Triangle::medicentre() {
	double x = a.getX() + b.getX() + c.getX() / 3;
	double y = a.getY() + b.getY() + c.getY() / 3;
	double z = a.getZ() + b.getZ() + c.getZ() / 3;
	return Point(x,y,z);
}

double Triangle::getLenghtOfSide(Point a, Point b)
{
 return sqrt(pow(a.getX() - b.getX(), 2) +
		pow(a.getY() - b.getY(), 2) +
		pow(a.getZ() - b.getZ(), 2));
}
bool Triangle::operator>(const Point & rhs) {
	return !isPointInTriangle(rhs);
}

bool Triangle::operator<(const Point & rhs)  {

	return isPointInTriangle(rhs);
}



bool Triangle::operator==(const Point & rhs)  {

	Vector ab(a, b);
	Vector ac(a, c);
	Vector bc(b, c);
	Vector pa(rhs, a);
	Vector pb(rhs, b);
	Vector pc(rhs, c);

	double area = (ab ^ ac).lenght() / 2;
	double aSide = (pb ^ pc).lenght() / (2 * area);
	double bSide = (pc ^ pa).lenght() / (2 * area);
	double cSide = 1 - aSide - bSide;

	if ((aSide == 0 && bSide <= 1 && bSide >= 0 && cSide <= 1 && cSide >= 0) ||
		(bSide == 0 && aSide <= 1 && aSide >= 0 && cSide <= 1 && cSide >= 0) ||
		(cSide == 0 && bSide <= 1 && bSide >= 0 && aSide <= 1 && aSide >= 0))
	{
		return true;
	}
	return false;
}
