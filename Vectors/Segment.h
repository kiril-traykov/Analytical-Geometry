#pragma once
#include"Line.h"
class Segment : public Line
{
	Point start;
	Point end;

public:
	Segment();
	Segment(Line, double, double);
	double LenghtSegment();
	Point Segment_mid();
	bool operator==(Point);
	~Segment();
};
