#pragma once
#include "stdafx.h"

class Vector{
public:
	Vector(float x, float y, float z);
	Vector();

	float getX() const;
	float getY() const;
	float getZ() const;
	float getLength();

	void normalize();
	void scale(float scalar);
	float dotWith(Vector other);
	Vector crossWith(Vector other);
	void subtract(Vector toSubtract);
	Vector copy();

private:
	float x;
	float y;
	float z;
	float mLength;

	void updateLength();
};

inline bool operator==(const Vector& lhs, const Vector& rhs){
	return eEqual(lhs.getX(), rhs.getX()) &&
		eEqual(lhs.getY(), rhs.getY()) &&
		eEqual(lhs.getZ(), rhs.getZ());
}
inline bool operator!=(const Vector& lhs, const Vector& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Vector& obj);