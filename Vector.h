#include "stdafx.h"

class Vector{
public:
	Vector(float x, float y, float z);
	Vector(Point from, Point to);

	float getX();
	float getY();
	float getZ();
	float getLength();

	bool isEqual(Vector toCompare);

	void normalize();
	void scale(float scalar);
	float dotWith(Vector other);
	void subtract(Vector toSubtract);

private:
	float x;
	float y;
	float z;
	float mLength;

	void updateLength();
};