#include "Line.h"

Line::Line()
{
}

Line::Line(Vector v, Point p) : Vector(v) {

	this->p = p;
	this->v = v;
}

Line::Line(Point a, Point b) : Vector(a, b)
{
	this->p = a;
	this->v = Vector(a, b);
}

Vector Line::direction()
{
	return *this;
}

double Line::angle(Line rhs)
{
	double ans;
	Point p1 = p;
	Point p2 = rhs.getPoint();
	double a = rand() % 10;
	double b = rand() % 10;
	double c = rand() % 10;
	Point p3(a, b, c);
	Vector f(p1, p2);
	Vector s(p1, p3);

	double sth = f * s;

	double lenghts = f.lenght() * s.lenght();

	ans = sth / lenghts;

	return ans;
}

Point Line::getPoint()
{
	return p;
}

Vector Line::getVector()
{
	return *this;
}

bool Line::operator+(Point v)
{   
	
	if (p.getX() * getX() + p.getY()*getY() + p.getZ()*getZ() == 0) { return true; }


	return false;
}

Vector Line::normalVector()
{
	double nx = getX() * this->p.getX();
	double ny = getY() * this->p.getY();
	double nz = getZ() * this->p.getZ();
	Vector normalVec(nx, ny, nz);
     
	return normalVec;
}

bool Line::operator==(Line rhs)
{
	bool areParalel = Paralel(rhs);
	if (areParalel == false) {
		return false;
	}
	if (Vector(p, rhs.getPoint()).Paralel(v)) {
		return true;
	}
	
	return false;
}

bool Line::operator||(Line rhs)
{
	return Paralel(rhs);
}

bool Line::operator&&(Line rhs)
{

	Vector tmp(p, rhs.getPoint());
	double scalar = operator()(tmp, rhs.getVector());

	if (scalar == 0) {
		if (*this || rhs) {
			return false;
		}
		else { return true; }
	}
	return false;
}

bool Line::operator!=(Line rhs)
{
	Vector tmp(p, rhs.getPoint());
	double scalar = operator()(tmp, rhs.getVector());

	if (scalar != 0) {
		if (*this || rhs) {
			return false;
		}
		else { return true; }
	}
	return false;
}

bool Line::operator|(Line rhs)
{
	if((*this).areSquare(rhs)) return true;
	return false;
}




Line::~Line()
{
}
