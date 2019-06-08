#pragma once
#include "Point.h"
#include <iostream>
#include "VectorLenghtException.h"

class Vector : public Point
{
public:
	Vector();
	Vector(const Point&, const Point&);
	Vector(double x1,double y1,double z1);
	Vector(Vector &);
	double lenght();
	Vector direction();
	Vector projection(Vector &);
	bool isZero();
	bool Paralel(Vector & v);
	bool areSquare(Vector & v);
	Vector& operator=(const Vector&);
	
	Vector  operator+(Vector & v);
	Vector operator-(Vector & v);
	double operator*(Vector & v);
	Vector  operator*(double a);
	Vector  operator^(Vector & v);
	double operator()(const Vector &a,const Vector&b);



	friend std::ostream & operator<<(std::ostream & os, Vector & v);
	friend std::istream & operator>>(std::istream & i, Vector & v);

	~Vector();
};

