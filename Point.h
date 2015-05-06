#pragma once
#include "stdafx.h"

class Point{
public:
	Point(float x, float y, float z);
	Point();

	float getX() const;
	float getY() const;
	float getZ() const;

	void translate(Vector toAdd);
	Point copy();
	float distance(Point other);
	float distanceSquared(Point other);

	static Vector differenceVector(Point one, Point two);
	static Vector vectorFromTo(Point from, Point to);

	std::wstring toString();
private:
	float x;
	float y;
	float z;
};

inline bool operator==(const Point& lhs, const Point& rhs){
	return eEqual(lhs.getX(), rhs.getX()) &&
		eEqual(lhs.getY(), rhs.getY()) && 
		eEqual(lhs.getZ(), rhs.getZ());
}
inline bool operator!=(const Point& lhs, const Point& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Point& obj);