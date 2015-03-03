#pragma once
#include "stdafx.h"

class Intersection{
public:
	Intersection(Sphere sphere, Point point);
	Intersection();

	Sphere mSphere;
	Point mPoint;

	Intersection copy();
};

inline bool operator==(const Intersection& lhs, const Intersection& rhs){
	return lhs.mPoint == rhs.mPoint &&
		lhs.mSphere == rhs.mSphere;
}
inline bool operator!=(const Intersection& lhs, const Intersection& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Intersection& obj);