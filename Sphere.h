#pragma once
#include "stdafx.h"

class Sphere : public Shape {
public:
	Sphere(Point center, float radius, Color color, Finish finish);
	Sphere();

	Point getCenter() const;
	float getRadius() const;

	Point rayIntersection(Ray toIntersect, bool* hitsSphere);
	Vector normalAtPoint(Point pt);

	Sphere* copy();
private:
	Point mCenter;
	float mRadius;
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