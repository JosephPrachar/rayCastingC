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
private:
	float x;
	float y;
	float z;
};