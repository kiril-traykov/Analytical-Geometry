#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"

using namespace std;

void onInit();
void pointMenu();
void vectorMenu();
void lineMenu();
void segmentMenu();
void triangleMenu();

int main()
{
	onInit();
	//Vector a(6,1,1);
	//Point p(5,5,1);
	//Point search(5, -5,0);
	//Line b (a, p);
	//Vector c;
	//c = b.normalVector();
	//cout << b + search;


}

void onInit() {
	int choice = 0;
	while (choice != 6) {
		cout << "1 - Point" << endl;
		cout << "2 - Vector" << endl;
		cout << "3 - Line" << endl;
		cout << "4 - Segment" << endl;
		cout << "5 - Triangle" << endl;
		cin >> choice;
		switch (choice) {

		case 1: pointMenu();
			break;
		case 2: vectorMenu();
			break;
		case 3: lineMenu(); break;
		case 4: segmentMenu(); break;
		case 5: triangleMenu();  break;
		}
	}
}

void pointMenu() {
	int choice;
	cout << "Enter x y and z " << endl;
	double x, y, z;
	cin >> x >> y >> z;
	Point point(x, y, z);
	cout << point << endl;
}

void vectorMenu() {
	int choice;
	double x, y, z;
	cout << "Cin x, y, z : ";
	cin >> x >> y >> z;
	Vector v(x,y,z);

	cout << "1. Vector's lenght" << endl;
	cout << "2. Vector's direction" << endl;
	cout << "3. Projection on vector on another vector" << endl; 
	cout << "4. Is Vector NULL ?" << endl;
	cout << "5. Are two vectors paralel (||)" << endl; 
	cout << "6. Are two vectors square (_!_)" << endl;
	cout << "7. Sum of two vectors" << endl;
	cout << "8. Substraction of two vectors" << endl;
	cout << "9. Multiplication of two vectors" << endl;
	cout << "10. Scalar Multiplication of two vectors" << endl; 
	cout << "11. Vectoral Multiplication of two vectors" << endl;
	cout << "12. Mixed Multiplication of three vectors" << endl;
	cin >> choice;


	Vector a;
	Vector b;

	switch (choice) {

	case 1: 
		cout << v.lenght()<<endl;
		
		break;
	case 2:
		a = v.direction();
		cout << a << endl;
		break;

	case 3:
		cout << "Enter x,y,z : " ;
		cin >> x >> y >> z; 
		a = Vector (x, y, z);
		a = v.projection(a);
		cout << a << endl;
		break;
	case 4: 
		cout << v.isZero() << endl; 
		break;
	case 5:
		cout << "Enter x,y,z : ";
		cin >> x >> y >> z;
		cout << v.Paralel(*(new Vector(x, y, z))) << endl;
		break;
	case 6:
		cout << "Enter x,y,z : ";
		cin >> x >> y >> z;
		cout << v.areSquare(*(new Vector(x, y, z))) << endl;
		break;
	case 7:
		cout << "Enter x,y,z : ";
		cin >> x >> y >> z;
		a = Vector(x, y, z);
		a = v + a;
		cout << a << endl;

		break;
	case 8:
		int mp;
		cout << "Please enter number" << endl;
		cin >> mp;
		a = v * mp;
		cout <<	a;
		
		break;
	case 9: 
		cout << "Enter x,y,z : ";
		cin >> x >> y >> z; 
			a = Vector(x, y, z);
			 a =  v ^ a;
			 cout << a;
			break;
	case 10: 
		cout << "Enter x,y,z : ";
		cin >> x >> y >> z;
		a =  Vector(x, y, z);
		cout << a * v;
		break;
	case 11:
		cout << "Enter x,y,z : ";
		cin >> x >> y >> z;
		a = Vector(x, y, z);
		cout << "Enter x,y,z : ";
		cin >> x >> y >> z;
		b = Vector(x, y, z);

		cout << v(a, b);

		break;
	}

}

void lineMenu() {
	int choice;
	double x, y, z;
	cout << "Cin x, y, z : ";
	cin >> x >> y >> z;
	Vector tmp;
	Vector v(x, y, z);
	cin >> x >> y >> z;
	Point p(x, y, z);
	Line l(v, p);
	Vector v2;
	Point p2;
	Line l2;
	cout << "1. Direction of line" << endl;
	cout << "2. Normal vector" << endl;
	cout << "3. Find the angle ! :) " << endl;
	cout << "4. Check if point lies on line (+)" << endl;
	cout << "5. Check if two lines are paralel (||) " << endl;
	cout << "6. Check if two lines are equal (==)" << endl;
	cout << "7. Check if two lines are crossing (&&) " << endl;
	cout << "8. Check if two lines make cross , jesus :) (!=) " << endl;
	cout << "9. Check if two lines are sqared (_!_) " << endl;
	cin >> choice;
	bool a;
	switch (choice) {

	case 1:
		tmp = l.direction();
		cout << tmp << endl;
		break;
	case 2:
		tmp = l.normalVector();
		cout << tmp << endl;
		break;
	case 3:
		cout << "Cin x, y, z : ";
		cin >> x >> y >> z;
		v2 = Vector(x, y, z);
		cin >> x >> y >> z;
		p2 = Point(x, y, z);
		l2 = Line(v2, p2);
		cout << l.angle(l2);

		break;
	case 4:
		cout << "Cin x, y, z : ";
		cin >> x >> y >> z;
		p2 = Point(x, y, z);
		cout << l + p2;

		break;
	case 5:
		cout << "Cin x, y, z : ";
		cin >> x >> y >> z;
		v2 = Vector(x, y, z);
		cin >> x >> y >> z;
		p2 = Point(x, y, z);
		l2 = Line(v2, p2);
		 a=  l || l2;
		cout << a;
		break;
	case 6:
		cout << "Cin x, y, z : ";
		cin >> x >> y >> z;
		v2 = Vector(x, y, z);
		cin >> x >> y >> z;
		p2 = Point(x, y, z);
		l2 = Line(v2, p2);
		a = l == l2;
		cout << a;

		break;
	case 7:
		cout << "Cin x, y, z : ";
		cin >> x >> y >> z;
		v2 = Vector(x, y, z);
		cin >> x >> y >> z;
		p2 = Point(x, y, z);
		l2 = Line(v2, p2);
		a = l && l2;
		cout << a;
		break;
	case 8:
		cout << "Cin x, y, z : ";
		cin >> x >> y >> z;
		v2 = Vector(x, y, z);
		cin >> x >> y >> z;
		p2 = Point(x, y, z);
		l2 = Line(v2, p2);
		a  = l != l2;
		cout << a;
		break;
	case 9:
		cout << "Cin x, y, z : ";
		cin >> x >> y >> z;
		v2 = Vector(x, y, z);
		cin >> x >> y >> z;
		p2 = Point(x, y, z);
		l2 = Line(v2, p2);
		a = l | l2;
		cout << a;
		break;
	}
}

void segmentMenu() {
	int choice;
	cout << "Enter coordinates of Line: " << endl;
	double x, y, z, t1, t2;
	cout << "Cin x, y, z : ";
	cin >> x >> y >> z;
	Vector tmp;
	bool liesOnPoint;
	Vector v(x, y, z);
	cin >> x >> y >> z;
	Point p(x, y, z);
	Line l(v, p);
	Point abc;
	cout << "Please enter interval: " << endl;
	cin >> t1 >> t2;
	Segment seg(l, t1, t2);
	cout << "1. lenght of segments" << endl;
	cout << "2. Mid of segment" << endl;
	cout << "3. Check if point lies on segment" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << seg.LenghtSegment() << endl;
	}
	if (choice == 2) {
		abc = seg.Segment_mid();
		cout << abc;
	}
	if (choice == 3) {
		cout << " enter cordinate of point " << endl;
		cin >> x >> y >> z;
		abc = Point(x, y, z);
		liesOnPoint = seg == abc;
		cout << liesOnPoint << endl;


	}
}

void triangleMenu()
{
	int choice;
	
	double a, b, c;
	cout << "Enter coos of Points" << endl;
	cin >> a >> b >> c;
	Point p1(a, b, c);
	cout << "Enter coos of Points" << endl;
	cin >> a >> b >> c;
	Point p2(a, b, c);
	cout << "Enter coos of Points" << endl;
	cin >> a >> b >> c;
	Point p3(a, b, c);
	
	Triangle t(p1, p2, p3);
		cout << "Triangle build attempted" << endl;


		cout << "For area of triangle press 1" << endl;
		cout << "For Perimeter of triangle press 2" << endl;
		cout << "For medicentre enter 3" << endl;
		cout << "For < operator press 4" << endl;
		cout << "For > operator press 5" << endl;
		cout << "For == operator press 6" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << t.area() << endl;
			break;
		case 2:
			cout << t.perimeter() << endl;
			break;

		case 3:
			 p1 = t.medicentre();
			cout << p1;
			break;
		case 4:
			cout << "Please enter a point " << endl;
			cin >> p2;
			cout << (t > p2);
			break;
		case 5:
			cout << "Please enter a point " << endl;
			cin >> p2;
			cout << (t < p2);
			break;
		case 6:
			cout << "Please enter a point " << endl;
			cin >> p2;
			cout << (t == p2);
			break;
		default:
			cout << "No such function" << endl;
			break;
		}


}
