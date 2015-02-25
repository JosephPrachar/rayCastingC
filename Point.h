#include "stdafx.h"

class Point{
public:
	Point(float x, float y, float z);

	float getX();
	float getY();
	float getZ();

	bool isEqual(Point toCompare);

	void translate(Vector toAdd);
private:
	float x;
	float y;
	float z;
};