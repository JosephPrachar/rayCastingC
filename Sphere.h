#pragma once
#include "stdafx.h"

class Sphere {
public:
	Sphere(Point center, float radius, Color color, Finish finish);

	Point getCenter();
	float getRadius();
	Color getColor();
	Finish getFinish();

	bool operator==(Sphere& rhs);
	bool operator!=(Sphere& rhs);

	Point rayIntersection(Ray toIntersect);
	Vector normalAtPoint(Point pt);
private:
	Point mCenter;
	float mRadius;
	Color mColor;
	Finish mFinish;
};