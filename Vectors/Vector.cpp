#include "Vector.h"
#include <cmath>

Vector::Vector()
{
}

Vector::Vector(const Point& p1, const Point& p2) : Point(p1.getX() - p2.getX(), p1.getY() - p2.getY(), p1.getZ() - p2.getZ())
{
}

Vector::Vector(double x1, double y1, double z1) : Point(x1, y1, z1)
{
}

Vector::Vector(Vector & v) : Point(v.getX(),v.getY(),v.getZ())
{
}

Vector& Vector::operator=(const Vector& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());
	return *this;
}

double Vector::lenght()
{
	return sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + pow(this->getZ(), 2));
}

Vector Vector::direction() 
{
	double nx, ny, nz;
	if (this->lenght() == 0) {
		throw VectorLenghtException();
	}
	double len = lenght();
	nx = getX() / len;
	ny = getY() / len;
	nz = getZ() / len;
	Vector tmp(nx,ny,nz);

	return tmp;
}

Vector Vector::projection(Vector & v)
{
	float scalar = *this * v;
	float len = v.lenght();
	float nx, ny, nz;
	float key = scalar / (pow(len, 2));
	nx = key * v.getX();
	ny = key * v.getY();
	nz = key * v.getZ();
	Vector tmp(nx, ny, nz);
	return tmp;
}

bool Vector::isZero()
{
	if (getX() == 0 && getY() == 0 && getZ() == 0) { return true; }
	return false;
}

bool Vector::Paralel(Vector & v)
{
	if (this->lenght() == 0 || v.lenght() == 0) {
		throw VectorLenghtException();
	}
double crossy = getY() / v.getY();
double crossx = getX() / v.getX();
double crossz = getZ() / v.getZ();
	
if (crossx == crossy) {
	if (crossx == crossz) { return true; }
}
return false;
	
}

bool Vector::areSquare(Vector & v)
{
	if (this->lenght() == 0 || v.lenght() == 0) {
		throw VectorLenghtException();
	}
	if (*this * v == 0) { return true; }
	return false;
}

Vector Vector::operator+(Vector & v)
{

	double nx, ny, nz;
	nx = getX() + v.getX();
	ny = getY() + v.getY();
	nz = getZ() + v.getZ();
	Vector tmp(nx, ny, nz);
	return tmp;
}

Vector Vector::operator-(Vector & v)
{
	double nx, ny, nz;
	nx = getX() - v.getX();
	ny = getY() - v.getY();
	nz = getZ() - v.getZ();

	Vector tmp(nx, ny, nz);
	return tmp;
}

double Vector::operator*(Vector & rhs)
{
	return getX()*rhs.getX() + getY()*rhs.getY() + getZ()*rhs.getZ();
}

Vector  Vector::operator*(double multiplicator)
{
	double nx, ny, nz;
	nx = getX()*multiplicator;
	ny = getY()*multiplicator;
	nz = getZ()*multiplicator;

	Vector tmp(nx, ny, nz);
	return tmp;
}

Vector Vector::operator^(Vector & rhs)
{
	double nx, ny, nz;
	nx = getY()*rhs.getZ() - getZ()*rhs.getY();
	ny = -getX()*rhs.getZ() + getZ()*rhs.getX();
	nz = getX()*rhs.getY() - getY()*rhs.getX();
	Vector b(nx, ny, nz);
	return b;

}

double Vector::operator()(const Vector & first,const  Vector & sec)
{

	double arr[3][3];
	arr[0][0] = getX();
	arr[0][1] = getY();
	arr[0][2] = getZ();
	arr[1][0] = first.getX();
	arr[1][1] = first.getY();
	arr[1][2] = first.getZ();
	arr[2][0] = sec.getX();
	arr[2][1] = sec.getY();
	arr[2][2] = sec.getZ();

	double determinant = arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1]))
		- arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0])) + arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[1][1]*arr[2][0]));

	return determinant;
}

std::ostream & operator<<(std::ostream & os, Vector & v)
{
	os << "x: " << v.getX() << " y: " << v.getY() << " z: " << v.getZ() << std::endl;
	return os;
}

std::istream & operator>>(std::istream & i, Vector & v)
{
	double a, b, c;
	i >> a >> b >> c;
	v.setX(a);
	v.setY(b);
	v.setZ(c);
	return i;
}

Vector::~Vector()
{
}