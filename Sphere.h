#include "stdafx.h"

class Sphere {
public:
	Sphere(Point center, float radius, Color color, Finish finish);

	// implement == and !=

	Point rayIntersection(Ray toIntersect);
	Vector normaAtPoint(Point pt);
private:
	Point mCenter;
	float mRadius;
	Color mColor;
	Finish mFinish;
};