#pragma once
#include "stdafx.h"

class Sphere {
public:
	Sphere(Point center, float radius, Color color, Finish finish);

	Point getCenter() const;
	float getRadius() const;
	Color getColor() const;
	Finish getFinish() const;

	Point rayIntersection(Ray toIntersect, bool* hitsSphere);
	Vector normalAtPoint(Point pt);

	Sphere copy();
private:
	Point mCenter;
	float mRadius;
	Color mColor;
	Finish mFinish;
};

inline bool operator==(const Sphere& lhs, const Sphere& rhs){
	return lhs.getCenter() == rhs.getCenter() &&
		eEqual(lhs.getRadius(), rhs.getRadius()) &&
		lhs.getColor() == rhs.getColor() &&
		lhs.getFinish() == rhs.getFinish();
}
inline bool operator!=(const Sphere& lhs, const Sphere& rhs){
	return !(lhs == rhs);
}

std::wstringstream& operator<<(std::wstringstream& os, const Sphere& obj);