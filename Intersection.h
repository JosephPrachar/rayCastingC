#pragma once
#include "stdafx.h"

class Intersection{
public:
	Intersection(Shape* shape, Point point);
	Intersection();

	Shape* mShape;
	Point mPoint;

	Intersection copy();
};

inline bool operator==(const Intersection& lhs, const Intersection& rhs){
	return lhs.mPoint == rhs.mPoint &&
		lhs.mShape == rhs.mShape;
}
inline bool operator!=(const Intersection& lhs, const Intersection& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Intersection& obj);