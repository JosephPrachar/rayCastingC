#pragma once
#include "stdafx.h"

class Point{
public:
	Point(float x, float y, float z);

	float getX();
	float getY();
	float getZ();

	bool operator==(Point& rhs);
	bool operator!=(Point& rhs);

	void translate(Vector toAdd);
	Point copy();
	float distance(Point other);
	float distanceSquared(Point other);

	static Vector vectorFromTo(Point from, Point to);
private:
	float x;
	float y;
	float z;
};