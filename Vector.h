#pragma once
#include "stdafx.h"

class Vector{
public:
	Vector(float x, float y, float z);

	float getX();
	float getY();
	float getZ();
	float getLength();

	bool operator==(Vector& rhs);
	bool operator!=(Vector& lhs);

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