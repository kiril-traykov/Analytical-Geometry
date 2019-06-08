#include "Segment.h"
#include"Point.h"
#include<cmath>


Segment::Segment()
{

}

Segment::Segment(Line coke, double t1, double t2) : Line(coke)
{
	double x = coke.getPoint().getX() + coke.getVector().getX() *t1;
	double y = coke.getPoint().getY() + coke.getVector().getY() *t1;
	double z = coke.getPoint().getZ() + coke.getVector().getZ() *t1;
	start = Point(x, y, z);

	double x1 = coke.getPoint().getX() + coke.getVector().getX() *t2;
	double y1 = coke.getPoint().getY() + coke.getVector().getY() *t2;
	double z1 = coke.getPoint().getZ() + coke.getVector().getZ() *t2;

	end = Point(x1, y1, z1);
}

double Segment::LenghtSegment()
{
	double ans = sqrt((start.getX() - end.getX())*((start.getX() - end.getX()) + (start.getY() - end.getY())*(start.getY() - end.getY()) + (start.getZ() - end.getZ())*(start.getZ() - end.getZ())));
	return ans;
}

Point Segment::Segment_mid()
{
	double ansX = (start.getX() + end.getX()) / 2;
	double ansY = (start.getY() + end.getY()) / 2;
	double ansZ = (start.getZ() + end.getZ()) / 2;
	return Point(ansX, ansY, ansZ);
}

bool Segment::operator==(Point p)
{
	if (*this + p) {
		if (p.getX() < end.getX() && p.getX() > start.getX() && p.getY() < end.getY() && p.getY() > start.getY() && p.getZ() < end.getZ() && p.getZ() > start.getZ())
			return true;
	}
	return false;
}


Segment::~Segment()
{
}
